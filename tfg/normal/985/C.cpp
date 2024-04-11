#include <cstdio>
#include <iostream>
#include <algorithm>

// ai que dor

const int ms = 100100;

int n, k, l;
int m;
int a[ms];

int main() {
	scanf("%d %d %d", &n, &k, &l);
	m = n * k;
	for(int i = 0; i < m; i++) {
		scanf("%d", a + i);
	}
	std::sort(a, a + m);
	if(a[n - 1] - a[0] > l) {
		printf("0\n");
		return 0;
	}
	int on = 0;
	while(on < m && a[on] - a[0] <= l) {
		on++;
	}
	on = std::min(on - 1, m - k);
	long long ans = 0;
	int freq = m - on;
	while(on >= 0) {
		if(freq >= k) {
			ans += a[on];
			freq -= k;
			//std::cout << "got barrel on " << on << " with value " << a[on] << std::endl;
		}
		freq++;
		on--;
	}
	std::cout << ans << std::endl;
}