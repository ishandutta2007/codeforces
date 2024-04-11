#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

const int MAX = 500009;
vector<int> adj[MAX];
int ord[26][MAX], inv[MAX], nv[MAX];
char ch[MAX];
int pp[MAX][20];
int dwn[MAX];
int nvst[MAX];
int d[MAX], f[MAX], tempo;


int dfs(int u) {
	d[u] = tempo++;
	for(int i = 1; i < 20; i++)
		pp[u][i] = pp[pp[u][i-1]][i-1];
	int mv = u;
	for(int v : adj[u]) {
		int vv = dfs(v);
		if(nv[vv] > nv[mv])
			mv = vv;
	}
	dwn[u] = mv;
	f[u] = tempo++;
	return dwn[u];
}
bool is_anc(int v, int u) {
	return d[v] >= d[u] && f[v] <= f[u];
}
int vec[MAX];

int main() {
	int i, j, n, m, x, y;
	scanf("%d %d", &n, &m);
	pp[0][0] = 0;
	for(i = 1; i < n; i++) {
		scanf("%d", &x);
		adj[x-1].pb(i);
		pp[i][0] = x-1;
	}
	for(i = 0; i < n; i++)
		scanf(" %c", &ch[i]);
	queue<int> q;
	q.push(0); i = 0; nv[0] = 1;
	int prev = -1; j = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		inv[u] = i;
		vec[i] = u;
		ord[ch[u] - 'a'][i++]++;
		if(prev == -1 || nv[u] > nv[prev]) nvst[++j] = i - 1;
		prev = u;
		for(int v : adj[u]) {
			q.push(v);
			nv[v] = nv[u] + 1;
		}
	}
	nvst[++j] = n;
	for(i = 1; i < n; i++)
		for(j = 0; j < 26; j++)
			ord[j][i] += ord[j][i - 1];
	dfs(0);	
	for(i = 0; i < m; i++) {
		scanf("%d %d", &x, &y); x--;
		int a = dwn[x];
		if(y < nv[x] || y > nv[a]) { puts("Yes"); continue; }
		for(j = 19; j >= 0; j--)
			if(nv[pp[a][j]] >= y)
				a = pp[a][j];
		//printf("%d of %d with nv %d [%d]\n", a, x, y, nv[a]);
		int sll = nvst[y], slr = inv[a];
		while(sll < slr) {
			int slm = (sll + slr) / 2;
			if(is_anc(vec[slm], x)) slr = slm;
			else sll = slm + 1;
		}
		int srl = inv[a], srr = nvst[y + 1] - 1;
		while(srl < srr) {
			int srm = (srl + srr + 1) / 2;
			if(is_anc(vec[srm], x)) srl = srm;
			else srr = srm - 1;
		}
		//printf("(%d, %d)\n", sll, srr);
		int imp = 0;
		for(j = 0; j < 26; j++) {
			int ab = 0;
			if(sll > 0) ab = ord[j][sll-1];
			if((ord[j][srr] - ab) & 1)
				imp++;
		}
		if(imp > 1) puts("No");
		else puts("Yes");
	}
	return 0;
}