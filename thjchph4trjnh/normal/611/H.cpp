#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

#define MAXV 1000010
#define MAXE 1000010
#define INF 1000000000
struct Dinic {
	int n, s, t, E, adj[MAXE], flow[MAXE], cap[MAXE], next[MAXE], last[MAXV], run[MAXV], level[MAXV], que[MAXV];
	void init(int _n, int _s, int _t) {
		n = _n; s = _s; t = _t; E = 0;
		for (int i = 0; i <= n; i++) last[i] = -1;
	}
	void add(int u, int v, int c1, int c2) {
		adj[E] = v; flow[E] = 0; cap[E] = c1; next[E] = last[u]; last[u] = E++;
		adj[E] = u; flow[E] = 0; cap[E] = c2; next[E] = last[v]; last[v] = E++;
	}
	bool bfs() {
		for (int i = 0; i <= n; i++) level[i] = -1;
		level[s] = 0;
		int qsize = 0;
		que[qsize++] = s;
		for (int i = 0; i < qsize; i++) {
			for (int u = que[i], e = last[u]; e != -1; e = next[e]) {
				int v = adj[e];
				if (flow[e] < cap[e] && level[v] == -1) {
					level[v] = level[u] + 1;
					que[qsize++] = v;
				}
			}
		}
		return level[t] != -1;
	}
	int dfs(int u, int bot) {
		if (u == t) return bot;
		for (int &e = run[u]; e != -1; e = next[e]) {
			int v = adj[e], delta = 0;
			if (level[v] == level[u] + 1 && flow[e] < cap[e] && (delta = dfs(v, min(bot, cap[e] - flow[e]))) > 0) {
				flow[e] += delta; flow[e ^ 1] -= delta;
				return delta;
			}
		}
		return 0;
	}
	int maxflow() {
		int total = 0;
		while (bfs()) {
			for (int i = 0; i <= n; i++) run[i] = last[i];
			for (int delta = dfs(s, INF); delta > 0; delta = dfs(s, INF)) total += delta;
		}
		return total;
	}
} dinic;

const int maxn = 200010;
int n, m;
int id[6][6];
int cnt[100];
int d[6];
int x[6];
int lst[6];
int com[maxn];
vi his;

int dj[6];
void init() {
	FOR(i, 0, 6) dj[i] = i;
}
int find(int u) {
	return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
void join(int u, int v) {
	int p = find(u);
	int q = find(v);
	dj[p] = q;
}

void rollback() {
	while (sz(his)) {
		cnt[his.back()]++;
		his.pop_back();
	}
}

int check(int k) {
	init();
	FOR(i, 0, k) {
		vi vv;
		FOR(j, 0, k + 1) {
			if (bit(x[i], j)) {
				vv.pb(j);
			}
		}
		assert(sz(vv) == 2);
		if (!cnt[id[vv[0]][vv[1]]]) {
			rollback();
			return 0;
		}
		cnt[id[vv[0]][vv[1]]]--;
		his.pb(id[vv[0]][vv[1]]);
		join(vv[0], vv[1]);
	}
	int ncom = 0;
	FOR(i, 0, k + 1) {
		ncom += dj[i] == i;
	}
	if (ncom != 1) {
		rollback();
		return 0;
	}
	int tot = (k + 1) * (k + 2);
	int s = tot++, t = tot++;
	dinic.init(tot, s, t);
	FOR(i, 0, k + 1) FOR(j, i, k + 1) {
		dinic.add(s, i * (k + 1) + j, cnt[id[i][j]], 0);
		dinic.add(i * (k + 1) + j, (k + 1) * (k + 1) + i, INF, 0);
		dinic.add(i * (k + 1) + j, (k + 1) * (k + 1) + j, INF, 0);
	}
	int sum = 0;
	FOR(i, 0, k + 1) {
		dinic.add((k + 1) * (k + 1) + i, t, d[i] - 1, 0);
		sum += d[i] - 1;
	}
	rollback();
	return dinic.maxflow() == sum;
}

void go(int k) {
	if (k == m - 1) {
		if (check(k)) {
			FOR(i, 0, k) {
				int tot = 0;
				FOR(j, 0, m) {
					if (bit(x[i], j)) {
						cout<<lst[j];
						if (++tot == 1) cout<<" ";
					}
				}
				cout<<"\n";
			}
			FOR(i, 0, m) FOR(j, i, m) {
				int u = i * (k + 1) + j;
				for (int e = dinic.last[u]; ~e; e = dinic.next[e]) {
					int v = dinic.adj[e];
					FOR(l, 0, dinic.flow[e]) {
						if ((k + 1) * (k + 1) + i != v) {
							cout<<lst[i]<<" "<<lst[j] + 1<<"\n";
							lst[j]++;
						}
						else {
							cout<<lst[j]<<" "<<lst[i] + 1<<"\n";
							lst[i]++;
						}
					}
				}
			}
			exit(0);
		}
		return;
	}
	FOR(i, 0, m) FOR(j, i + 1, m) {
		x[k] = (1 << i) | (1 << j);
		go(k + 1);
	}
}

void solve() {
	FOR(i, 0, 6) FOR(j, 0, 6) {
		id[i][j] = i * 6 + j;
	}
	cin>>n;
	FOR(i, 0, n - 1) {
		string s, t; cin>>s>>t;
		int u = sz(s) - 1, v = sz(t) - 1;
		if (u > v) swap(u, v);
		cnt[id[u][v]]++;
	}
	FOR(i, 1, n + 1) {
		if (i < 10) {d[0]++; m = 1; com[i] = 0; lst[0] = 1;}
		else if (i < 100) {d[1]++; m = 2; com[i] = 1; lst[1] = 10;}
		else if (i < 1000) {d[2]++; m = 3; com[i] = 2; lst[2] = 100;}
		else if (i < 10000) {d[3]++; m = 4; com[i] = 3; lst[3] = 1000;}
		else if (i < 100000) {d[4]++; m = 5; com[i] = 4; lst[4] = 10000;}
		else if (i < 1000000) {d[5]++; m = 6; com[i] = 5; lst[5] = 100000;}
	}
	go(0);
	cout<<-1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}