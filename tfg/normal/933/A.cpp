#include <iostream>

int lr[2020][2020][2];
int rl[2020][2020][2];

int a[2020];
int freq[2020];

int main() {
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if(a[i] == 2) freq[i]++;
		freq[i] += freq[i - 1];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			lr[i][j][0] = lr[i][j - 1][0] + (a[j] == 1);
			lr[i][j][1] = std::max(lr[i][j - 1][1] + (a[j] == 2), lr[i][j - 1][0] + 1);
		}
	}
	for(int i = n; i > 0; i--) {
		for(int j = i; j > 0; j--) {
			rl[i][j][0] = rl[i][j + 1][0] + (a[j] == 1);
			rl[i][j][1] = std::max(rl[i][j + 1][1] + (a[j] == 2), rl[i][j + 1][0] + 1);
		}
	}
	int ans = lr[1][n][1];
	//std::cout << "got " << ans << "\n";
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			ans = std::max(ans, lr[1][i - 1][0] + rl[j][i][1] + freq[n] - freq[j]);
			//std::cout << "on (" << i << ", " << j << ") got " << lr[1][i - 1][0] + rl[i][j][1] + freq[n] - freq[j] << "\n";
		}
	}
	std::cout << ans << '\n';
}