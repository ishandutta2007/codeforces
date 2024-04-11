#include <iostream>
#include <cstdio>

const int ms = 100100;

int freq[ms][2];
int a[ms][2];

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 2; j++) {
			scanf("%d", a[i] + j);
			freq[a[i][j]][j]++;
		}
	}
	for(int i = 0; i < n; i++) {
		int h = (n - 1) + freq[a[i][1]][0];
		printf("%d %d\n", h, 2 * (n - 1) - h);
	}
}