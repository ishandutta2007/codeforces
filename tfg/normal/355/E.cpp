#include <iostream>
#include <cstdio>

const int ms = 2001000;

int freq[ms];

int main() {
	int n, k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		freq[t]++;
	}
	for(int i = 1; i < ms; i++) {
		freq[i] += freq[i - 1];
	}
	int ans = 1;
	for(int i = 2; i + i < ms; i++) {
		int got = 0;
		for(int j = i; j + i < ms; j += i) {
			got += freq[std::min(j + k, j + i - 1)] - freq[j - 1];
		}
		if(got == n) {
			ans = i;
		}
	}
	std::cout << ans << '\n';
}