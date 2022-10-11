#include <iostream>
#include <cstdio>

const int ms = 1000200;

int sum[ms][10];
int f[ms];
int g[ms];

int main() {
	f[0] = 1;
	for(int i = 1; i < ms; i++) {
		f[i] = f[i / 10] * (std::max(1, i % 10));
		if(i < 10) {
			g[i] = i;
		} else {
			g[i] = g[f[i]];
		}
	}
	for(int i = 1; i < 50; i++) {
		//std::cout << i << ", " << f[i] << ", " << g[i] << "\n";
	}
	for(int i = 1; i < ms; i++) {
		sum[i][g[i]]++;
	}
	for(int i = 1; i < ms; i++) {
		for(int j = 0; j < 10; j++) {
			sum[i][j] += sum[i - 1][j];
		}
	}
	int q;
	std::cin >> q;
	while(q--) {
		int l, r, k;
		scanf("%i %i %i", &l, &r, &k);
		printf("%i\n", sum[r][k] - sum[l - 1][k]);
	}
}