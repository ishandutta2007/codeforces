#include <bits/stdc++.h>
using namespace std;

const int MaxN = 200005;

int x[MaxN], y[MaxN];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d%d", &x[i], &y[i]);
	}
	if (n & 1) printf("No\n");
	else {
		int t = -1;
		int tx = x[1] - x[0], ty = y[1] - y[0];
		for (int i = 1; i < n; ++ i) {
			int nxt = (i + 1) % n;
			int nx = x[nxt] - x[i], ny = y[nxt] - y[i];
			if (1ll * tx * ny == 1ll * nx * ty) {
				t = i;
				break;
			}
		}
		if (t == -1) printf("No\n");
		else {
			bool flag = true;
			for (int i = 0; i < n; ++ i) {
				int ii = (i + 1) % n, tt = (t + 1) % n;
				int x1 = x[ii] - x[i], y1 = y[ii] - y[i];
				int x2 = x[tt] - x[t], y2 = y[tt] - y[t];
				if (1ll * x1 * x1 + 1ll * y1 * y1 != 1ll * x2 * x2 + 1ll * y2 * y2) {
					flag = false;
					break;
				}
				if ((1ll * x1 * y2 != 1ll * x2 * y1)) {
					flag = false;
					break;
				}
				t = tt;
			}
			if (flag) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}