#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 1123456;
int S[N], sz[N], g[N];
int a[1009][1009], ok[1009][1009];
int M[1009][1009], seen[1009][1009];
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};
inline int id(int i, int j) { return i * 1000 + j; }

int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}

void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	S[b] = a;
}


int n, m;
inline bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }

void dfs(int i, int j, int &ne, int I) {
	if(seen[i][j] || find(id(i, j)) != I) return;
	seen[i][j] = true;
	if(ne) ne--, M[i][j] = 1;
	for(int d = 0; d < 4; d++) {
		int ni = i + di[d], nj = j + dj[d];
		if(!valid(ni, nj)) continue;
		dfs(ni, nj, ne, I);
	}
}

int main() {
	ll k; int i, j, d;
	scanf("%d %d %I64d", &n, &m, &k);
	vector<pii> v;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			S[id(i, j)] = id(i, j), sz[id(i, j)] = 1;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			scanf("%d", &a[i][j]), v.pb(pii(i, j));
	sort(v.begin(), v.end(), [](pii x, pii y) { return a[x.fst][x.snd] > a[y.fst][y.snd]; });
	for(pii x : v) {
		i = x.fst, j = x.snd;
		ok[i][j] = 1;
		for(d = 0; d < 4; d++) {
			int ni = i + di[d], nj = j + dj[d];
			if(!valid(ni, nj) || !ok[ni][nj]) continue;
			join(id(i, j), id(ni, nj));
		}
		if(k % a[i][j]) continue;
		int V = a[i][j];
		int I = find(id(i, j));
		if(ll(sz[I]) < (k / ll(a[i][j]))) continue;
		puts("YES");
		int ne = (k / a[i][j]);
		dfs(i, j, ne, I);
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++)
				if(M[i][j]) printf("%d ", V);
				else printf("0 ");
			putchar('\n');
		}
		return 0;
	}
	puts("NO");
}