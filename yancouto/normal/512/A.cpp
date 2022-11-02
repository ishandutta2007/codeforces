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

vector<int> adj[26];
int seen[26], d[26], e[26], f[26], tempo;
void dfs(int u) {
	if(seen[u]) return;
	seen[u] = true;
	for(int v : adj[u])
		dfs(v);
	e[u] = tempo++;
	f[25 - e[u]] = u;
}

char s[200][200];
int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%s", s[i]);
	bool bad = false;
	for(i = 0; i < n - 1; i++) {
		for(j = 0; s[i][j] && s[i+1][j] && s[i][j] == s[i+1][j]; j++);
		if(s[i+1][j] == 0) bad = true;
		if(!s[i][j] || !s[i+1][j]) continue;
		adj[s[i][j] - 'a'].pb(s[i+1][j] - 'a');
	}
	for(i = 0; i < 26; i++)
		dfs(i);
	for(i = 0; i < 26; i++)
		for(int v : adj[i])
			if(e[v] > e[i])
				bad = true;
	if(bad) { puts("Impossible"); return 0; }
	for(i = 0; i < 26; i++)
		putchar('a' + f[i]);
	putchar('\n');
}