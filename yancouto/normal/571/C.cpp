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
const int MAX = 200009;
int var[2][MAX];
vector<pii> adj[MAX]; vector<int> vs[MAX];
int val[MAX], ok[MAX], seen[MAX];
int myvar[MAX];

void propagate(int u) {
	ok[u] = true;
	for(pii p : adj[u]) {
		if(ok[p.fst]) continue;
		if(abs(p.snd) == myvar[u]) continue;
		val[abs(p.snd)] = (p.snd < 0);
		myvar[p.fst] = abs(p.snd);
		propagate(p.fst);
	}
}

bool dfs(int u, int x, int p) {
	if(seen[u]) {
		val[abs(x)] = (x < 0);
		myvar[u] = abs(x);
		propagate(u);
		return true;
	}
	seen[u] = 1;
	for(pii e : adj[u]) {
		if(e.fst == p && abs(e.snd) == abs(x)) continue;
		if(dfs(e.fst, e.snd, u)) return true;
	}
	return false;
}

int k[MAX];
int main() {
	int i, n, m, j, x;
	scanf("%d %d", &n, &m);
	memset(var, -1, sizeof var);
	for(i = 0; i < n; i++) {
		scanf("%d", &k[i]);
		for(j = 0; j < k[i]; j++) {
			scanf("%d", &x);
			if(var[x > 0][abs(x)] != -1) {
				adj[i].pb(pii(var[x > 0][abs(x)], x));
				adj[var[x > 0][abs(x)]].pb(pii(i, -x));
			}
			var[x < 0][abs(x)] = i;
			vs[i].pb(x);
		}
	}
	for(i = 0; i < n; i++)
		if(!ok[i] && adj[i].size() != k[i]) {
			for(int x : vs[i])
				if(var[x > 0][abs(x)] == -1) {
					val[abs(x)] = (x > 0);
					myvar[i] = abs(x);
					break;
				}
			propagate(i);
		}
	for(i = 0; i < n; i++)
		if(!ok[i] && !seen[i])
			dfs(i, 0, -1);
	for(i = 0; i < n; i++)
		if(!ok[i])
			break;
	if(i < n) puts("NO");
	else {
		puts("YES");
		for(i = 1; i <= m; i++)
			printf("%d", val[i]);
		putchar('\n');
	}
	return 0;
}