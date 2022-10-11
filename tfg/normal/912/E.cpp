#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

typedef long long ll;

int n;
int a[20];

std::vector<ll> sides[2];

ll count(ll x) {
	int l = 0, r = sides[1].size() - 1;
	ll ans = 0;
	while(l < sides[0].size()) {
		while(r >= 0 && ((double)sides[1][r] * sides[0][l] > 2e18 || sides[1][r] * sides[0][l] > x)) {
			r--;
		}
		ans += r + 1;
		l++;
	}
	//std::cout << "for " << x << " got " << ans << "\n";
	return ans;
}

bool prime(int x) {
	for(int i = 2; i < x; i++) {
		if(x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	/*for(int i = 2; n < 16; i++) {
		if(prime(i)) {
			a[n++] = i;
		}
	}*/
	srand(time(0));
	std::random_shuffle(a, a + n);
	ll k;
	std::cin >> k;
	if(n == 1) {
		ll ans = 1;
		k--;
		while(k--) {
			ans *= a[0];
		}
		std::cout << ans << '\n';
	} else {
		std::set<ll> nums;
		nums.insert(1);
		int kk = 1.5e6;
		while(!nums.empty() && kk--) {
			ll cur = *nums.begin();
			sides[0].push_back(cur);
			nums.erase(cur);
			for(int i = 0; i < n / 2; i++) {
				if(ll(2e18) / a[i] >= cur) {
					nums.insert(cur * a[i]);
				}
			}
			while(nums.size() > kk) {
				auto it = nums.end();
				it--;
				nums.erase(it);
			}
		}
		//std::cout << "first end\n";
		nums.insert(1);
		kk = 1.5e6;
		while(!nums.empty() && kk--) {
			ll cur = *nums.begin();
			sides[1].push_back(cur);
			//std::cout << cur << '\n';
			nums.erase(cur);
			for(int i = n / 2; i < n; i++) {
				if(ll(2e18) / a[i] >= cur) {
					nums.insert(cur * a[i]);
				}
			}
			while(nums.size() > kk) {
				auto it = nums.end();
				it--;
				nums.erase(it);
			}
		}
		//std::cout << "second end\n";
		std::sort(sides[0].begin(), sides[0].end());
		std::sort(sides[1].begin(), sides[1].end());
		ll l = 1, r = 1e18;
		while(l != r) {
			ll mid = (l + r) / 2;
			if(count(mid) < k) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		std::cout << l << '\n';
	}
}