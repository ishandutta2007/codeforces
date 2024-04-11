#include <cstdio>

int t, x[3], y[3], n;

int dx[4] = {-1, 1, -1, 1};
int dy[4] = {-1, -1, 1, 1};

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int j = 0; j < 3; ++j) {
			scanf("%d%d", x + j, y + j);
			--x[j];
			--y[j];
		}
		int cnt[3] = {0};
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 4; ++j) {
				int xx = x[i] + dx[j], yy = y[i] + dy[j];
				for (int k = 0; k < 3; ++k) if (xx == x[k] && yy == y[k]) ++cnt[k];
			}
		}
		int id;
		for (id = 0; cnt[id] == 1; ++id);
		int xx, yy;
		scanf("%d%d", &xx, &yy);
		--xx;
		--yy;
		bool ok = 1;
		if (!x[id] && !y[id] || !x[id] && y[id] == n - 1 || !y[id] && x[id] == n - 1 || x[id] == n - 1 && y[id] == n - 1) {
			ok = 0;
			if (x[id] == xx || y[id] == yy) ok = 1;
		}
		x[id] -= 1;
		y[id] -= 1;
		printf("%s\n", !ok || xx - x[id] & 1 ^ 1 && yy - y[id] & 1 ^ 1 ? "NO" : "YES");
	}
	return 0;
}