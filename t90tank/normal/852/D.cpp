#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int N = 811;

int V, E, n, m;
#define forl(i) for(int i = 1; i <= n; i ++)

vi e[N]; int mat[N];
bool v[N];
int lev[N];
bool extend(int x) {
	for(int i : e[x]) if(lev[mat[i]] == lev[x] + 1)
		if(!mat[i] || extend(mat[i])) {
			mat[i] = x; mat[x] = i; return 1;
		}
	lev[x] = 0;
	return 0;
}

int q[N], *qb, *qe;
int hopcraft(int n) {
	int re = 0;
	fill(mat, mat + n + 1, 0);
	for(;;) {
		qb = qe = q; fill(lev, lev + n + 1, 0);
		forl(i) if(!mat[i]) lev[*qe++ = i] = 1;
		while(qb != qe) {
			int x = *qb ++;
			if(lev[0]) break;
			for(int j : e[x]) if(!lev[mat[j]])
				lev[*qe++ = mat[j]] = lev[x] + 1;
		}
		if(!lev[0]) break;
		forl(i) if(!mat[i]) re += extend(i);
	}
	return re;
}

int dis[N][N];

const int inf = 1e9L;
vector <pair <int, int>> ie[N];
void dij(int s, int *d) {
	for(int i = 1; i <= V; i ++) d[i] = inf; d[s] = 0;
	set <pair <int, int>> st;
	for(int i = 1; i <= V; i ++)
		st.insert({d[i], i});
	while(!st.empty()) {
		int x = st.begin() -> second; st.erase(st.begin());
		for(auto i : ie[x]) {
			int v = i.fir, w = i.sec;
			if(d[v] > d[x] + w) {
				st.erase({d[v], v});
				d[v] = d[x] + w;
				st.insert({d[v], v});
			}
		}
	}
}

int s[N];

bool solve(int lim) {
	for(int i = 1; i <= V + n; i ++)
		e[i].clear();
	//cout << "------\n";
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= V; j ++)
			if(dis[s[i]][j] <= lim) {
				//cout << lim << ' ' << i << ' ' << j << '\n';
				e[i].pb(j + n);
				e[j + n].pb(i);
			}
	int i = hopcraft(V + n); //cout << i << '\n';
	if(i >= m)
		return 1;
	return 0;
}

int main() {
	cin >> V >> E >> n >> m;
	for(int i = 1; i <= n; i ++)
		scanf("%d", s + i);
	for(int i = 1; i <= E; i ++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		ie[u].pb({v, w}); 
		ie[v].pb({u, w});
	}
	for(int i = 1; i <= V; i ++)
		dij(i, dis[i]);
	
	int l = 0, r = inf;
	while(l + 1 < r) {
		int im = (l + r) / 2;
		if(solve(im - 1))
			r = im;
		else
			l = im;
	}
	if(l == inf - 1) l = -1;
	cout << l << '\n';
	
	return 0;
}