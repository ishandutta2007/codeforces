#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
int x[N], y[N], ordx[N], ordy[N];

bool byx(int i, int j) {
	return x[i] < x[j];
}

bool byy(int i, int j) {
	return y[i] < y[j];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", x + i, y + i);
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ordx[i] = i;
		ordy[i] = i;
	}
	sort(ordx, ordx + n, byx);
	sort(ordy, ordy + n, byy);
	int flag1 = 0, flag2 = 0;
	for (int i = 0; i < n >> 1; ++i) {
		if (y[ordx[i]] <= y[ordy[n - 2 >> 1]]) {
			++flag1;
		}
		if (y[ordx[i]] >= y[ordy[n >> 1]]) {
			++flag2;
		}
	}
	bool flag3 = false;
	for (int i = 0; i < n && !flag3; ++i) {
		if (x[i] == x[ordx[n >> 1]] && y[i] == y[ordy[n >> 1]]) {
			flag3 = true;
		}
	}
	sort(x, x + n);
	sort(y, y + n);
	for (int i = 0; i < n >> 1; ++i) {
		ans -= x[i] + y[i];
		ans += x[n - i - 1] + y[n - i - 1];
	}
	if (flag1 < (n >> 1) && flag2 < (n >> 1)) {
		if (~n & 1) {
			int dx = x[n >> 1] - x[n - 2 >> 1],
				dy = y[n >> 1] - y[n - 2 >> 1];
			ans -= min(dx, dy);
		} else if (flag3) {
			int dx = min(x[n >> 1] - x[n - 2 >> 1], x[n + 1 >> 1] - x[n >> 1]),
				dy = min(y[n >> 1] - y[n - 2 >> 1], y[n + 1 >> 1] - y[n >> 1]);
			ans -= min(dx, dy);
		}
	}
	ans <<= 1;
	cout << ans << endl;
	return 0;
}