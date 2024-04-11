#include <iostream>

const int ms = 100100;

int w[ms];
int sum[ms];

int main() {
	int n, l, r, ql, qr;
	std::cin >> n >> l >> r >> ql >> qr;
	for(int i = 1; i <= n; i++) {
		std::cin >> w[i];
		sum[i] = sum[i - 1] + w[i];
	}
	int onl = 1, onr = n;
	bool left = true;
	int ans = 1e9;
	int cur = 0;
	while(onl <= onr) {
		if(left) {
			ans = std::min(ans, cur + (sum[onr] - sum[onl - 1]) * l + (onr - onl) * ql);
			cur += w[onl++] * l;
		} else {
			ans = std::min(ans, cur + (sum[onr] - sum[onl - 1]) * r + (onr - onl) * qr);
			cur += w[onr--] * r;
		}
		left = !left;
	}
	cur = 0;
	onl = 1, onr = n;
	left = false;
	while(onl <= onr) {
		if(left) {
			ans = std::min(ans, cur + (sum[onr] - sum[onl - 1]) * l + (onr - onl) * ql);
			cur += w[onl++] * l;
		} else {
			ans = std::min(ans, cur + (sum[onr] - sum[onl - 1]) * r + (onr - onl) * qr);
			cur += w[onr--] * r;
		}
		left = !left;
	}
	std::cout << ans << '\n';
}