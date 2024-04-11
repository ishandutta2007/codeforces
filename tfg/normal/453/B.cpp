#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>

std::string get_bin(int n, int rest = 10) {
	if(rest == 0) {
		return "";
	} else {
		return get_bin(n / 2, rest - 1) + char('0' + n % 2);
	}
}

typedef std::pair<int, int> ii;

const int MAGIC = 100;

bool prime(int n) {
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

std::vector<int> primes, rest;

std::vector<ii> a;
int memo[101][1 << 10];
int use[101][1 << 10];
int typ[MAGIC + 1];
int hmm[MAGIC + 1];
int trans[101];

int abss(int x) {
	return std::max(x, -x);
}

int dp(int on, int mask) {
	if(on == a.size()) {
		return 0;
	}
	int &ans = memo[on][mask];
	if(ans != -1) {
		return ans;
	}
	ans = 1e8;
	for(int i = 1; i <= MAGIC; i++) {
		//if(hmm[i] == 1 && (typ[i] & mask) == 0 && on == 7 && mask == 508) {
		//	std::cout << "trying to use " << i << " on mask " << mask << "\n";
		//	std::cout << "got answer for rest " << dp(on + 1, mask | typ[i]) << '\n';
		//}
		if(hmm[i] == 1 && (typ[i] & mask) == 0 && dp(on + 1, mask | typ[i]) + abss(i - a[on].first) < ans) {
			ans = dp(on + 1, mask | typ[i]) + abss(i - a[on].first);
			use[on][mask] = i;
		}
	}
	//if(mask == 0)
	//std::cout << "getting next primes starting from " << on << " is cost " << rest[a.size() - on - 1] - trans[on] << "\n";
	if(rest[a.size() - on - 1] - trans[on] < ans) {
		//std::cout << "got special case\n";
		ans = rest[a.size() - on - 1] - trans[on];
		use[on][mask] = rest[0];
	}
	return ans;
}

int ans[101];

int main() {
	for(int i = 1; i <= MAGIC; i++) {
		hmm[i] = i;
	}
	for(int i = 2; i <= 30; i++) {
		if(prime(i)) {
			primes.push_back(i);
			for(int j = i; j <= MAGIC; j += i) {
				typ[j] |= (1 << (primes.size() - 1));
				while(hmm[j] % i == 0) {
					hmm[j] /= i;
				}
			}
		}
	}
	int n;
	std::cin >> n;
	for(int i = 31; rest.size() < n; i++) {
		if(prime(i)) {
			rest.push_back(i);
			//std::cout << i << '\n';
			if(rest.size() > 1) {
				rest[rest.size() - 1] += rest[rest.size() - 2];
			}
		}
	}
	for(int i = 0; i < n; i++) {
		int t;
		std::cin >> t;
		a.push_back(ii(t, i));
	}
	std::sort(a.begin(), a.end());
	for(int i = n - 1; i >= 0; i--) {
		trans[i] = trans[i + 1] + a[i].first;
	}
	memset(memo, -1, sizeof memo);
	//std::cout << dp(0, 0) << '\n';
	dp(0, 0);
	int on = 0, mask = 0;
	while(on < n && hmm[use[on][mask]] == 1) {
	//	std::cout << "on " << on << " using " << use[on][mask] << ", mask is " << get_bin(mask) << " or " << mask << "\n";
	//	std::cout << "cost for rest is " << memo[on][mask] << ", or " << rest[a.size() - on - 1] - trans[on] << '\n';
		
		ans[a[on].second] = use[on][mask];
		mask |= typ[use[on][mask]];
		on++;
	}
	for(int i = 0; on < n; i++, on++) {
		if(i) {
			ans[a[on].second] = rest[i] - rest[i - 1];
		} else {
			ans[a[on].second] = rest[i];
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}