#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdio>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300300;
const int me = 64;

int bits[ms];
int typ[ms][me];
int count[ms];

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int sum = 0;
	typ[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		long long val;
		scanf("%lld", &val);
		int curB = 0;
		while(val) {
			curB += (int) (val & 1);
			val /= 2;
		}
		sum = (sum + curB) % 2;
		typ[i][0] = typ[i-1][0];
		typ[i][1] = typ[i-1][1];
		typ[i][sum]++;
		count[i] = curB;
		bits[i] = (bits[i-1] + curB) % 2;
		//std::cout << "on pos " << i << " has " << curB << '\n';
	}
	long long ans = 0;
	for(int r = 1; r <= n; r++) {
		if(r > me + 30 || 1) {
			// do smart thing
			sum = 0;
			int mx = 0;
			int l = r;
			while(l > 0 && sum <= me * 2) {
				sum += count[l];
				if(mx < count[l]) {
					mx = count[l];
				}
				if(mx <= sum - mx && sum % 2 == 0) {
					ans++;
				}
				//std::cout << "on [" << l << ", " << r << "], mx is " << mx << ", sum is " << sum << "\n";
				l--;
			}
			if(l == 0) continue;
			l--;
			//std::cout << "ended with l " << l << std::endl;
			int curType = typ[r][0] != typ[r-1][0] ? 0 : 1;
			assert(curType == bits[r]);
			ans += typ[l][curType];
		} else {
			// do brute
			sum = 0;
			int mx = 0;
			for(int l = r; l > 0; l--) {
				sum += count[l];
				if(mx < count[l]) {
					mx = count[l];
				}
				if(mx <= sum - mx && sum % 2 == 0) {
					ans++;
				}
				//std::cout << "on [" << l << ", " << r << "], mx is " << mx << ", sum is " << sum << "\n";
			}
		}
	}
	std::cout << ans << std::endl;
}