#include <iostream>
#include <algorithm>

const int ms = 300100;

int n, k;
int a[ms];
bool dp[ms];

bool can(int x) {
	//std::cout << "testing " << x << "\n";
	for(int i = 0; i <= n + 1; i++) {
		dp[i] = false;
	}
	dp[1] = true;
	for(int l = 1, r = 1; l <= n; l++) {
		if(!dp[l]) {
			continue;
		}
		while(r <= n && a[r] - a[l] <= x) {
			r++;
			if(r - l >= k) {
				//std::cout << "from " << l << " to " << r << "\n";
				dp[r] = true;
			} else {
				//std::cout << "skipped " << r << "\n";
			}
		}
	}
	return dp[n + 1];
}

int main() {
	std::cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + n + 1);
	int l = 0, r = 1e9 + 10;
	while(l != r) {
		int mid = (l + r) / 2;
		if(can(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << l << '\n';
}