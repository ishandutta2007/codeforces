#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

typedef int num;
const int N = 212;
const int M = 11234 * 2;
const num eps = 0;

struct dinic {
	int hd[N], seen[N], qu[N], lv[N], ei[N], to[M], nx[M];
	num fl[M], cp[M];
	int en = 2;
	int tempo = 0;

	// Reset the whole graph
	void reset(int n=N) { en = 2; memset(hd, 0, sizeof(int) * n); }
	// Reset only the flow
	void reset_flow() { memset(fl, 0, sizeof(num) * en); }

	// edge from a to b with cap c and edge from b to a with cap rc
	void add_edge(int a, int b, num c, num rc=0) {
		to[en] = b; nx[en] = hd[a]; fl[en] = 0; cp[en] = c; hd[a] = en++;
		to[en] = a; nx[en] = hd[b]; fl[en] = 0; cp[en] = rc; hd[b] = en++;
	}

	bool bfs(int s, int t) {
		seen[t] = ++tempo;
		lv[t] = 0;
		int ql = 0, qr = 0;
		qu[qr++] = t;
		while(ql != qr) {
			t = qu[ql++];
			ei[t] = hd[t];
			if(s == t) return true;
			for(int e = hd[t]; e; e = nx[e])
				if(seen[to[e]] != tempo && cp[e ^ 1] - fl[e ^ 1] > eps) {
					seen[to[e]] = tempo;
					lv[to[e]] = lv[t] + 1;
					qu[qr++] = to[e];
				}
		}
		return false;
	}

	num dfs(int s, int t, num f) {
		if(s == t) return f;
		for(int &e = ei[s]; e; e = nx[e])
			if(ei[to[e]] && seen[to[e]] == tempo && cp[e] - fl[e] > eps && lv[to[e]] == lv[s] - 1)
				if(num rf = dfs(to[e], t, min(f, cp[e] - fl[e]))) {
					fl[e] += rf;
					fl[e ^ 1] -= rf;
					return rf;
				}
		return 0;
	}

	num max_flow(int s, int t) {
		num fl = 0;
		while(bfs(s, t))
			while(num f = dfs(s, t, numeric_limits<num>::max()))
				fl += f;
		return fl;
	}
};

dinic d;

char S[112][112], C[112][112];

int di[] = {1, -1, 0,  0};
int dj[] = {0,  0, 1, -1};

int n;
pii o;

int ds[11][11][11][11];
void go(int si, int sj) {
	queue<pii> q;
	q.push(pii(si, sj));
	ds[si][sj][si][sj] = 0;
	while(!q.empty()) {
		pii x = q.front(); q.pop();
		int i = x.fst, j = x.snd;
		if((o.fst != si || o.snd != sj) && ds[o.fst][o.snd][i][j] != -1 && ds[si][sj][i][j] >= ds[o.fst][o.snd][i][j]) continue;
		for(int d = 0; d < 4; d++) {
			int ni = i + di[d], nj = j + dj[d];
			if(ni < 0 || nj < 0 || ni >= n || nj >= n || C[ni][nj] == 'Y' || ds[si][sj][ni][nj] != -1) continue;
			ds[si][sj][ni][nj] = ds[si][sj][i][j] + 1;
			q.push(pii(ni, nj));
		}
	}
}

int main() {
	memset(ds, -1, sizeof ds);
	int i, j, T;
	scanf("%d %d", &n, &T);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf(" %c", &S[i][j]);
	vector<pii> st;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			scanf(" %c", &C[i][j]);
			if(isdigit(C[i][j])) {
				st.pb(pii(i, j));
			}
			if(C[i][j] == 'Z')
				o = pii(i, j);
		}
	go(o.fst, o.snd);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(C[i][j] != 'Y')
				go(i, j);
	int s = 2 * n * n, t = 2 * n * n + 1;
	for(i = 0; i < st.size(); i++) {
		int si = st[i].fst, sj = st[i].snd;
		d.add_edge(s, i, S[si][sj] - '0');
		d.add_edge(i + n * n, t, C[si][sj] - '0');
		for(j = 0; j < st.size(); j++) {
			int d = ds[si][sj][st[j].fst][st[j].snd];
			int d2 = ds[o.fst][o.snd][st[j].fst][st[j].snd];
			//if(C[st[j].fst][st[j].snd] != '0')
			//	printf("(%d, %d) get %d\n", i, j, d);
			if(d != -1 && d <= T && (d2 == -1 || d <= d2)) ::d.add_edge(i, j + n * n, 10000);
			//if(d != -1 && d <= T && (d2 == -1 || d <= d2) && S[si][sj] != '0' && C[st[j].fst][st[j].snd] != '0') printf("(%d, %d) -> (%d, %d)\n", si, sj, st[j].fst, st[j].snd);
		}
	}
	printf("%d\n", d.max_flow(s, t));
}