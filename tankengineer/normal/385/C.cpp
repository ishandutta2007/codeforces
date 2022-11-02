#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int M = 10000000 + 1;
int f[M], c[M];

int main() {
	f[1] = 1;
	for (int i = 2; i < M; ++i) {
		if (f[i] == 0) {
			f[i] = i;
			for (long long j = (long long)i * i; j < M; j += i) {
				f[j] = i;
			}
		}
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);
		while (t != 1) {
			int d = f[t];
			++c[d];
			while (t % d == 0) {
				t /= d;
			}
		}
	}
	for (int i = 1; i < M; ++i) {
		c[i] += c[i - 1];
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		r = min(r, M - 1);
		if (l > r) {
			printf("0\n");
		} else {
			printf("%d\n", c[r] - c[l - 1]);
		}
	}
	return 0;
}