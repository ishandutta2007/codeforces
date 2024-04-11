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
const int N = 503;
int adj2[N][N], a[N];
ll adj[N][N][2], ans[N];
int main() {
	int i, j, k, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &adj2[i][j]);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	reverse(a, a + n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			adj[i][j][1] = adj2[a[i]][a[j]];
	for(k = 0; k < n; k++) {
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				adj[i][j][k&1] = min(adj[i][j][!(k&1)], adj[i][k][!(k&1)] + adj[k][j][!(k&1)]);
		for(i = 0; i <= k; i++)
			for(j = 0; j <= k; j++)
				ans[k] += adj[i][j][k&1];
	}
	for(i = n - 1; i >= 0; i--)
		printf("%I64d ", ans[i]);
	putchar('\n');
}