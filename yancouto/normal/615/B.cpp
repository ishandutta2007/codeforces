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
vector<int> adj[N];

int memo[N];
int solve(int i) {
	int &r = memo[i];
	if(r != -1) return r;
	r = 1;
	for(int v : adj[i])
		r = max(r, 1 + solve(v));
	return r;
}
int deg[N];
int main() {
	int i, n, m, a, b;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		if(a > b) swap(a, b);
		adj[b].pb(a);
		deg[a]++; deg[b]++;
	}
	memset(memo, -1, sizeof memo);
	ll mx = 0;
	for(i = 0; i < n; i++)
		mx = max(mx, ll(solve(i)) * ll(deg[i]));
	printf("%I64d\n", mx);
}