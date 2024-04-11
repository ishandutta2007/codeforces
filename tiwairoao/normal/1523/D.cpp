#include <bits/stdc++.h>

typedef long long ll;

const int N = 400000;

ll a[N + 5]; int n1, n, m, p;
void read(ll &x) {
	char str[64] = {}; scanf("%s", str);
	for (int i = 0; i < m; i++) x = (x << 1) | (str[i] - '0');
}
void print(const ll &x, const int &k) {
	if (k) print(x >> 1, k - 1);
	putchar((x & 1) + '0');
}

ll res; int bts[(1 << 15) + 5], mx;
void update(int x) {
	static int b[64]; int cnt = 0;
	for (int i = 0; i < m; i++)
		if ((a[x] >> i) & 1) b[cnt++] = i;
	assert (cnt <= p);

	int s = (1 << cnt);
	static int f[1 << 15];
	for (int i = 0; i < s; i++) f[i] = 0;
	for (int i = 1; i <= n; i++) {
		int t = 0;
		for (int j = 0; j < cnt; j++)
			if ((a[i] >> b[j]) & 1) t |= (1 << j);
		f[t]++;
	}
	for (int j = 0; j < cnt; j++) for (int i = 0; i < s; i++) if ((i >> j) & 1)
		f[i ^ (1 << j)] += f[i];
	for (int i = 0; i < s; i++) if (f[i] >= n1 && bts[i] > mx) {
		res = 0;
		for (int j = 0; j < cnt; j++) if ((i >> j) & 1) res |= (1ll << b[j]);
		mx = bts[i];
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &p), n1 = (n + 1) >> 1;
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i < (1 << p); i++) bts[i] = bts[i >> 1] + (i & 1);

	std::mt19937 gen(20041112);
	std::uniform_int_distribution<int>ud(1, n);
	for (int i = 1; i <= 40; i++) update(ud(gen));
	print(res, m - 1);
}