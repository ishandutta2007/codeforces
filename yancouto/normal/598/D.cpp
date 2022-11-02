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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
const int N = 1010009;
int S[N], sz[N], pics[N];
int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}
inline int id(int i, int j) { return i * 1001 + j; }
inline int find(int i, int j) { return find(id(i, j)); }

void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	pics[a] += pics[b];
	S[b] = a;
}

bool seen[1002][1002];
char g[1002][1002];

void dfs(int i, int j) {
	if(seen[i][j]) return;
	seen[i][j] = true;
	for(int d = 0; d < 4; d++) {
		int ni = i + dx[d], nj = j + dy[d];
		if(g[ni][nj] == '.') {
			dfs(ni, nj);
			join(id(i, j), id(ni, nj));
		} else {
			pics[find(i, j)]++;
		}
	}
}

int main() {
	int i, j, x, y, n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(i = 0; i < N; i++) S[i] = i, sz[i] = -1;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			scanf(" %c", &g[i][j]);
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			if(g[i][j] == '.')
				dfs(i, j);
	for(i = 0; i < k; i++) {
		scanf("%d %d", &x, &y); x--; y--;
		printf("%d\n", pics[find(x, y)]);
	}
}