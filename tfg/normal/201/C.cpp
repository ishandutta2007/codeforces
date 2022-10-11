#include <iostream>
#include <cstdio>

typedef long long ll;

const int ms = 100100;

int a[ms];
ll left[ms][2];
ll right[ms][2];

int main() {
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		scanf("%d", a + i);
	}
	for(int i = 1; i < n; i++) {
		left[i][0] = left[i - 1][0] + a[i];
		if(a[i] % 2 == 0) {
			left[i][0]--;
			left[i][0] = std::max(left[i][0], left[i - 1][1] + a[i]);
		}
		if(a[i] != 1) {
			left[i][1] = left[i - 1][1] + a[i];
			if(a[i] % 2 == 1) {
				left[i][1]--;
			}
		}
	}
	for(int i = n - 2; i >= 0; i--) {
		right[i][0] = right[i + 1][0] + a[i + 1];
		if(a[i + 1] % 2 == 0) {
			right[i][0]--;
			right[i][0] = std::max(right[i][0], right[i + 1][1] + a[i + 1]);
		}
		if(a[i + 1] != 1) {
			right[i][1] = right[i + 1][1] + a[i + 1];
			if(a[i + 1] % 2 == 1) {
				right[i][1]--;
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans = std::max(ans, std::max(left[i][1] + right[i][0], right[i][1] + left[i][0]));
	}
	std::cout << ans << '\n';
}