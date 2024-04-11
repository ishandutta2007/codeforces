#include <bits/stdc++.h>

#define pr std::make_pair

typedef long long ll;

const int N = 1000;
const ll INF = (1ll << 60);

namespace flowG{
	const int V = 2*N;
	const int E = 20*V;

	int to[E + 5]; ll cap[E + 5]; int cnte;
	std::vector<int>G[V + 5]; int cur[V + 5];
	void adde(int u, int v, ll c) {
		int p = (cnte++), q = (cnte++);
		G[u].push_back(p), to[p] = v, cap[p] = c;
		G[v].push_back(q), to[q] = u, cap[q] = 0;
		// printf("! %d %d %lld\n", u, v, c);
	}

	int d[V + 5], s, t;
	bool relabel() {
		for (int i = s; i <= t; i++) d[i] = t + 5, cur[i] = 0;

		static int que[V + 5]; int hd, tl;
		d[que[hd = tl = 1] = t] = 0;
		while (hd <= tl) {
			int x = que[hd++];
			for (auto e : G[x]) if (cap[e ^ 1] && d[to[e]] > d[x] + 1)
				d[que[++tl] = to[e]] = d[x] + 1;
		}

		return d[s] != t + 5;
	}
	ll aug(int x, ll tot) {
		if (x == t) return tot; ll sum = 0;
		for (int &i = cur[x]; i < (int)G[x].size(); i++) {
			int e = G[x][i];
			if (cap[e] && d[x] == d[to[e]] + 1) {
				ll del = aug(to[e], std::min(tot - sum, cap[e]));
				cap[e] -= del, cap[e ^ 1] += del, sum += del;
				if (sum == tot) break;
			}
		}
		return sum;
	}
	ll min_cut(int _s, int _t) {
		ll f = 0; s = _s, t = _t;
		while (relabel()) f += aug(s, INF);
		return f;
	}
}

int idi[N + 5], ido[N + 5], cnt;
int x[N + 5], y[N + 5], w[N + 5], n;
std::map<std::pair<int, int>, int>mpi, mpo;
int main() {
	scanf("%d", &n); ll sum = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &x[i], &y[i], &w[i]), sum += w[i];
	
	int s = 0, t = (n << 1) + 1;
	for (int i = 1; i <= n; i++) {
		idi[i] = mpi[pr(x[i], y[i])] = (i << 1) - 1;
		ido[i] = mpo[pr(x[i], y[i])] = (i << 1);
		flowG::adde(idi[i], ido[i], w[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (x[i] & 1) {
			if (y[i] & 1) {
				flowG::adde(s, idi[i], INF);
				if (mpi.count(pr(x[i] - 1, y[i]))) flowG::adde(ido[i], mpi[pr(x[i] - 1, y[i])], INF);
			} else {
				if (mpo.count(pr(x[i] - 1, y[i]))) flowG::adde(mpo[pr(x[i] - 1, y[i])], idi[i], INF);
				flowG::adde(ido[i], t, INF);
			}
		} else {
			if (y[i] & 1) {
				if (mpo.count(pr(x[i] - 1, y[i]))) flowG::adde(mpo[pr(x[i] - 1, y[i])], idi[i], INF);
				if (mpi.count(pr(x[i], y[i] - 1))) flowG::adde(ido[i], mpi[pr(x[i], y[i] - 1)], INF);
			} else {
				if (mpo.count(pr(x[i], y[i] - 1))) flowG::adde(mpo[pr(x[i], y[i] - 1)], idi[i], INF);
				if (mpi.count(pr(x[i] - 1, y[i]))) flowG::adde(ido[i], mpi[pr(x[i] - 1, y[i])], INF);
			}
		}
	}
	printf("%lld\n", sum - flowG::min_cut(s, t));
}