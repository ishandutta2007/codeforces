#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int P = 100005;
int n, m, p, x, y, z;

int main() {
	scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &z, &p);
	x %= 4, y %= 2, z %= 4;
	for (int i = 0; i < p; ++i) {
		int nn = n, mm = m, x, y;
		scanf("%d%d", &x, &y);
		for (int j = 0; j < ::x; ++j) {
			int nx = y, ny = n + 1 - x;
			x = nx, y = ny;
			swap(n, m);
		}
		for (int j = 0; j < ::y; ++j) {
			y = m + 1 - y;
		}
		for (int j = 0; j < ::z; ++j) {
			int nx = m + 1 - y, ny = x;
			x = nx, y = ny;
			swap(n, m);
		}
		printf("%d %d\n", x, y);
		n = nn, m = mm;
	}
	return 0;
}