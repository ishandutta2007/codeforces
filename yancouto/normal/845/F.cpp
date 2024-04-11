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
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n, m;

ll memo[260][1 << 15][2][2];
char g[250][250];

ll solve(int i, int j, int bm, bool cur_col, bool any) {
	if(j == m) return 1;
	if(i == n) return solve(0, j + 1, bm, false, any);
	if(g[i][j] == 'x') return solve(i + 1, j, bm & (~(1 << i)), false, any);
	ll &r = memo[i * m + j][bm][cur_col][any];
	if(r != -1) return r;
	r = 0;
	if(cur_col || ((bm >> i) & 1)) r += solve(i + 1, j, bm, cur_col, any);
	else if(!any) r += solve(i + 1, j, bm, cur_col, true);
	r += solve(i + 1, j, bm | (1 << i), true, any);
	return r = mod(r);
}

int main() {
	memset(memo, -1, sizeof memo);
	int i, j;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			if(n < m) scanf(" %c", &g[i][j]);
			else scanf(" %c", &g[j][i]);
		}
	if(n > m) swap(n, m);
	printf("%d\n", int(solve(0, 0, 0, 0, 0)));
}