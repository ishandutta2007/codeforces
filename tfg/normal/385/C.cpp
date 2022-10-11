#include <iostream>
#include <cstdio>

const int ms = 1e7 + 10;

int freq[ms];
int sum[ms];
bool np[ms];

int main() {
	int n;
	std::cin >> n;
	while(n--) {
		int t;
		scanf("%d", &t);
		freq[t]++;
	}
	for(int i = 2; i < ms; i++) {
		sum[i] = sum[i - 1];
		if(np[i]) {
			continue;
		}
		for(int j = i; j < ms; j += i) {
			sum[i] += freq[j];
			np[j] = true;
		}
	}
	std::cin >> n;
	while(n--) {
		int l, r;
		scanf("%d %d", &l, &r);
		r = std::min(r, ms - 1);
		l = std::min(l, r);
		printf("%d\n", sum[r] - sum[l - 1]);
	}
}