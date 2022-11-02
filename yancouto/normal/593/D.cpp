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
const int N = 200009;
int va[N], vb[N]; ll vc[N];

int S[N];
int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}

int lv[N], pai[N];
void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(lv[a] > lv[b]) swap(a, b);
	S[b] = a;
}


inline int ot(int u, int e) { return va[e] == u? vb[e] : va[e]; }
vector<int> adj[N];
int dfs(int u, int pe, int lv) {
	::lv[u] = lv;
	pai[u] = pe;
	for(int e : adj[u])
		if(e != pe) {
			dfs(ot(u, e), e, lv + 1);
			if(vc[e] == 1) S[ot(u, e)] = u;
		}
}

ll proc(ll y, int a, int b) {
	a = find(a); b = find(b);
	if(lv[a] > lv[b]) swap(a, b);
	while(lv[b] > lv[a]) {
		if(b) y /= vc[pai[b]];
		if(y == 0) return 0;
		b = find(ot(b, pai[b]));
	}
	while(a != b) {
		if(a) y /= vc[pai[a]];
		if(b) y /= vc[pai[b]];
		if(y == 0) return 0;
		a = find(ot(a, pai[a]));
		b = find(ot(b, pai[b]));
	}
	return y;
}

int main() {
	int i, n, m, a, b, op; ll y;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d %I64d", &va[i], &vb[i], &vc[i]);
		va[i]--; vb[i]--;
		adj[va[i]].pb(i);
		adj[vb[i]].pb(i);
	}
	for(i = 0; i < n; i++)
		S[i] = i;
	dfs(0, -1, 0);
	for(i = 0; i < m; i++) {
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d %d %I64d", &a, &b, &y); a--; b--;
			printf("%I64d\n", proc(y, a, b));
		} else {
			scanf("%d %I64d", &a, &y);
			vc[a - 1] = y;
			if(y == 1) join(va[a - 1], vb[a - 1]);
		}
	}
}