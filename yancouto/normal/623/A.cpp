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
const int N = 509;
vector<int> adj[N];
int S[N], sz[N];
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
char s[N];
int M[N][N];

int main() {
	int i, j, n, m, a, b;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) S[i] = i, sz[i] = 1, M[i][i] = 1;
	for(i = 0; i < m; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
		M[a][b] = M[b][a] = 1;
	}
	for(i = 0; i < n; i++)
		if(adj[i].size() == n - 1)
			s[i] = 'b';
	for(i = 0; i < n; i++)
		if(s[i] != 'b')
			for(int v : adj[i])
				if(s[v] != 'b')
					join(i, v);
	set<int> se;
	for(i = 0; i < n; i++)
		if(s[i] != 'b')
			se.insert(find(i));
	if(se.size() > 2) { puts("No"); return 0; }
	for(i = 0; i < n; i++)
		if(s[i] != 'b') {
			if(find(i) == *se.begin()) s[i] = 'a';
			else s[i] = 'c';
		}
	for(i = 0; i < n; i++)
		if(s[i] != 'b')
			for(j = 0; j < n; j++)
				if(s[j] == s[i] && !M[i][j]) {
					puts("No");
					return 0;
				}
	puts("Yes");
	puts(s);
}