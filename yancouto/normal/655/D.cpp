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
const int N = 100009;

int u[N], v[N], deg[N], n;
vector<int> adj[N];

bool ok(int m) {
	int i;
	for(i = 0; i < n; i++) adj[i].clear(), deg[i] = 0;
	for(i = 0; i <= m; i++) adj[u[i]].pb(v[i]), deg[v[i]]++;
	vector<int> v;
	for(i = 0; i < n; i++) if(deg[i] == 0) v.pb(i);
	while(!v.empty()) {
		if(v.size() > 1) return false;
		int x = v.back(); v.clear();
		for(int w : adj[x])
			if((--deg[w]) == 0)
				v.pb(w);
	}
	return true;
}

int main() {
	int i, m;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++)
		scanf("%d %d", &u[i], &v[i]), u[i]--, v[i]--;
	if(!ok(m - 1)) { puts("-1"); return 0; }
	int l = 0, r = m - 1;
	while(l < r) {
		int mi = (l + r) / 2;
		if(ok(mi)) r = mi;
		else l = mi + 1;
	}
	printf("%d\n", l + 1);
}