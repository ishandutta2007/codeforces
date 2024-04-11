#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;
const int N = 1000010;
int n, m;
int c[N];
vector <int> colors[510];
int ans = 1;
int dp[510][510];
int l[510], r[510];
int order_l[510], order_r[510];
int tmpl[510], tmpr[510];
int f[N];
vector <pair<int, int>> v[N];

bool cmpl(int x, int y) {
	return l[x] < l[y];
}

bool cmpr(int x, int y) {
	return r[x] < r[y];
}


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &c[i]);
		colors[c[i]].push_back(i);
	}
	set <int> id;
	id.insert(0);
	id.insert(m + 1);

	for (int i = 1; i <= n; i++) {
		assert(!colors[i].empty());
		int l = colors[i].front(), r = colors[i].back();
		// int R = *id.lower_bound(r);
		auto it = id.lower_bound(l);
		if (*it <= r) {
			printf("0\n");
			return 0;
		}
		it--;
		// int L = *it;
 	}

 	for (int i = 1; i <= n; i++)
 		l[i] = colors[i].front(), r[i] = colors[i].back();

 	for (int i = 1; i <= n; i++)
 		order_l[i] = i;
 	sort(order_l + 1, order_l + n + 1, cmpl);
 	for (int i = 1; i <= n; i++)
 		order_r[i] = i;
 	sort(order_r + 1, order_r + n + 1, cmpr);
 	l[0] = 0;
 	r[0] = m + 1;

 	for (int i = n; i; i--) {

 		memset(tmpl, 0, sizeof tmpl);
 		tmpl[i] = 1;
 		for (int j = n; j; j--) {
 			for (int k = i; k <= n; k++)
 				if (l[c[r[k] + 1]] == r[k] + 1)
	 				tmpl[order_l[j]] = (tmpl[order_l[j]] + 1LL * tmpl[c[r[k] + 1]] * dp[order_l[j]][k]) % P;
 		}

		memset(tmpr, 0, sizeof tmpr);
 		tmpr[i] = 1;
 		for (int j = 1; j <= n; j++) {
 			for (int k = i; k <= n; k++)
 				if (r[c[l[k] - 1]] == l[k] - 1)
	 				tmpr[order_r[j]] = (tmpr[order_r[j]] + 1LL * tmpr[c[l[k] - 1]] * dp[k][order_r[j]]) % P;
 		}

 		for (int j = i; j <= n; j++)
 			for (int k = i; k <= n; k++)
 				dp[j][k] = (dp[j][k] + 1LL * tmpl[j] * tmpr[k]) % P;
 	}

 	for (int i = 1; i <= n; i++)
 		for (int j = 1; j <= n; j++) {
 			// if (dp[i][j])
 			// 	printf("%d %d %d\n", l[i], r[j], dp[i][j]);
 			v[l[i] - 1].push_back(make_pair(r[j], dp[i][j]));
 		}

 	f[0] = 1;
 	for (int i = 0; i <= m; i++) {
 		for (auto p: v[i])
 			f[p.first] = (f[p.first] + 1LL * p.second * f[i]) % P;
 	}
 	printf("%d\n", f[m]);
}