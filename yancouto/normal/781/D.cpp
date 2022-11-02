#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;
const int N = 512, L = 61;

bitset<500> adj[2][N];

bool seen[N][L][2];
bitset<500> memo[N][L][2];
bitset<500> &solve(int a, int i, bool f) {
	if(i == 0) return adj[f][a];
	bitset<500> &r = memo[a][i][f];
	if(seen[a][i][f]) return r;
	seen[a][i][f] = true;
	bitset<500> &b1 = solve(a, i - 1, f);
	for(int b = 0; b < n; b++)
		if(b1[b])
			r |= solve(b, i - 1, !f);

	return r;
}
ll mx[2][L][N];

int main() {
	int i, j, m, a, b, t;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &t); a--; b--;
		adj[t][a][b] = 1;
	}
	for(i = 0; i < n; i++)
		if(solve(i, 60, false).any()) {
			puts("-1");
			return 0;
		}
	for(i = 0; i < n; i++)
		mx[0][0][i] = solve(i, 0, false).any(),
		mx[1][0][i] = solve(i, 0, true).any();
	for(int l = 1; l < 60; l++)
		for(int g = 0; g < 2; g++) {
			for(i = 0; i < n; i++) {
				mx[g][l][i] = mx[g][l - 1][i];
				bitset<500> &b = solve(i, l, g);
				if(b.any()) {
					mx[g][l][i] = (1ll << l);
					for(j = 0; j < n; j++)
						if(b[j]) {
							mx[g][l][i] = max(mx[g][l][i], (1ll << l) + mx[!g][l - 1][j]);
						}
				}
			}
		}
	ll ans = 0;
	for(i = 0; i < n; i++)
		ans = max(ans, mx[0][59][i]);
	if(ans > 1000000000000000000ll) puts("-1");
	else printf("%lld\n", ans);
}