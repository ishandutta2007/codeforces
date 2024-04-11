#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200;

int x[N], y[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", x + i, y + i);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int st = 0;
		for (int j = 0; j < n; ++j) {
			if (x[i] == x[j]) {
				if (y[i] > y[j]) {
					st |= 1;
				} else if (y[i] < y[j]) {
					st |= 1 << 1;
				}
			}
			if (y[i] == y[j]) {
				if (x[i] > x[j]) {
					st |= 1 << 2;
				} else if (x[i] < x[j]) {
					st |= 1 << 3;
				}
			}
		}
		if (st == (1 << 4) - 1) {
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}