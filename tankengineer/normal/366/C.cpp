#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100, BAR = 10000, M = BAR * 2 + 1;
int n, k, bag[M], aa[N], bb[N];

int main() {
	scanf("%d%d", &n, &k);
	memset(bag, -1, sizeof(bag));	
	bag[BAR] = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", aa + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", bb + i);
	}
	for (int i = 0; i < n; ++i) {
		int a = aa[i], b = bb[i];
		b *= k;
		b -= a;
		if (b <= 0) {
			for (int j = 0; j < M; ++j) {
				if (bag[j] == -1) {
					continue;
				}
				if (j + b >= 0 && j + b < M) {
					bag[j + b] = max(bag[j + b], bag[j] + a);
				}
			}
		} else {
			for (int j = M - 1; j >= 0; --j) {
				if (bag[j] == -1) {
					continue;
				}
				if (j + b >=0 && j + b < M) {
					bag[j + b] = max(bag[j + b], bag[j] + a);
				}
			}
		}
	}
	if (bag[BAR] == 0) {
		printf("-1\n");
	} else {
		printf("%d\n", bag[BAR]);
	}
	return 0;
}