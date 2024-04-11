#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int c[5] = {500, 1000, 1500, 2000, 2500};

int main() {
	int m[5], w[5], hs, hu, ans = 0;
	for (int i = 0; i < 5; ++i) {
		scanf("%d", m + i);
	}
	for (int i = 0; i < 5; ++i) {
		scanf("%d", w + i);
	}
	scanf("%d%d", &hs, &hu);
	for (int i = 0; i < 5; ++i) {
		ans += max(c[i] * 3 / 10, (250 - m[i]) * c[i] / 250 - 50 * w[i]);
	}
	ans += hs * 100 - hu * 50;
	printf("%d\n", ans);
	return 0;
}