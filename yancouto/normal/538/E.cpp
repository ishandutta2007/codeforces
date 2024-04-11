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

int deg[200009];
vector<int> adj[200009];
int m1[200009][2];
int s1(int i, bool mx) {
	int &r = m1[i][mx];
	if(r != -1) return r;
	if(adj[i].empty()) return r = 1;
	if(mx) {
		r = INT_MAX;
		for(int v : adj[i])
			r = min(r, s1(v, !mx));
	} else {
		r = 0;
		for(int v : adj[i])
			r += s1(v, !mx);
	}
	return r;
}

int main() {
	int i, n, m = 0, a, b;
	scanf("%d", &n);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		adj[--a].pb(--b);
		deg[a]++;
	}
	memset(m1, -1, sizeof m1);
	for(i = 0; i < n; i++)
		if(!deg[i])
			m++;
	printf("%d %d\n", m - s1(0, true) + 1, s1(0, false));
}