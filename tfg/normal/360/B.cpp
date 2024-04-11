#include <iostream>
#include <utility>
#include <cstdlib>

typedef long long ll;
typedef std::pair<ll, ll> ii;

const int ms = 2020;
const ll INF = 1e5;

int n, k;
int a[ms];
int dp[ms];

bool valid(ll ans) {
	for(int i = 0; i < n; i++) {
		dp[i] = i;
	}
	//std::cout << "testing " << ans << std::endl;
	for(int i = 0; i < n; i++) {
		//std::cout << "on " << i << " got " << dp[i] << std::endl;
		if(dp[i] + n - i - 1 <= k) return true;
		for(int j = i + 1; j < n; j++) {
			//std::cout << "to " << j << ", " << abs(a[i] - a[j]) << ", " << (abs(a[i] - a[j]) + j - i + 1) / (j - i) << std::endl;
			if(((ll)abs(a[i] - a[j]) + j - i - 1) / (j - i) <= ans) {
				//std::cout << "could go to " << j << std::endl;
				dp[j] = std::min(dp[j], dp[i] + j - i - 1);
			}
		}
	}
	//std::cout << "end is " << dp[n - 1] << std::endl;
	return false;
}



int main() {
	std::cin >> n >> k;
	int mx = -1e9, mn = 1e9;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		mx = std::max(mx, a[i]);
		mn = std::min(mn, a[i]);
	}
	ll l = 0, r = 2e9;
	while(l != r) {
		ll mid = ((ll)l + r) / 2;
		if(valid(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << l << std::endl;
}