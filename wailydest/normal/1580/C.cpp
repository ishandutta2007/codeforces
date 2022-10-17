#include <cstdio>

const int N = 200000;
const int K = 500;

int n, m, add[K][K], x[N], y[N], inc[N], ans, last[N];

void upd(int cur, int ind, int d) 
{
	if (x[ind] + y[ind] >= K) {
		inc[cur] -= d;
		for (int i = cur + x[ind]; i < m; i += x[ind] + y[ind]) {
			inc[i] += d;
			if (i + y[ind] < m) inc[i + y[ind]] -= d;
		}
	}
	else {
		add[x[ind] + y[ind]][(cur + x[ind]) % (x[ind] + y[ind])] += d;
		add[x[ind] + y[ind]][cur % (x[ind] + y[ind])] -= d;
	}
}

int main() 
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d%d", x + i, y + i);
	for (int i = 0; i < m; ++i) {
		int op, k;
		scanf("%d%d", &op, &k);
		--k;
		if (op == 1) {
			upd(i, k, 1);
			last[k] = i;
			++ans;
		}
		for (int j = 1; j < K; ++j) ans += add[j][i % j];
		ans += inc[i];
		if (op == 2) {
			upd(last[k], k, -1);
			if ((i - last[k]) % (x[k] + y[k]) >= x[k]) --ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}