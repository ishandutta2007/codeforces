#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif
const int N = 1009;

int di[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dj[8] = {0, 0, -1, 1, 1, -1, -1, 1};

int mx[8][N][N];
ll ans[8][N][N];
int k2[8][N][N];
int k3[8][N][N];
char g[N][N];

ll fexp(ll x, ll p) {
	ll r = 1;
	for(; p; p >>= 1, x = mod(x * x))
		if(p & 1)
			r = mod(r * x);
	return r;
}

inline ll inv(ll x) { return fexp(x, modn - 2); }
int n;
inline bool valid(int i, int j) { return min(i, j) >= 0 && max(i, j) < n; }

int seen[8][N][N];

void dfs(int i, int j, int d) {
	if(seen[d][i][j]) return;
	seen[d][i][j] = true;
	int ni = i + di[d], nj = j + dj[d];
	if(!valid(ni, nj) || g[ni][nj] == '0') { mx[d][i][j] = 0; ans[d][i][j] = 1 /*ou 0*/; return; }
	dfs(ni, nj, d);
	mx[d][i][j] = 1 + mx[d][ni][nj];
	ans[d][i][j] = mod(ans[d][ni][nj] * ll(g[ni][nj] - '0'));
	k2[d][i][j] = k2[d][ni][nj] + (g[ni][nj] == '2');
	k3[d][i][j] = k3[d][ni][nj] + (g[ni][nj] == '3');
}

ll best = 1;
int b2 = 0, b3 = 0;

typedef long double ld;
const ld l3 = log2(ld(3));

bool better(ll v, int k2, int k3) {
	return k2 - b2 > (b3 - k3) * l3;
}

void go(int o) {
	int i, j, d;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			if(g[i][j] == '0') continue;
			ll r = g[i][j] - '0'; int c2 = (g[i][j] == '2'), c3 = (g[i][j] == '3');
			int g = INT_MAX;
			for(d = o; d < o + 4; d++)
				g = min(g, mx[d][i][j]);
			debug("at %d, %d: cross of %d\n", i, j, g);
			if(g)
				for(d = o; d < o + 4; d++) {
					int ni = i + di[d] * g, nj = j + dj[d] * g;
					int C2 = k2[d][i][j], C3 = k3[d][i][j];
					if(valid(ni, nj)) C2 -= k2[d][ni][nj], C3 -= k3[d][ni][nj];
					c2 += C2; c3 += C3;
				}
			debug("at %d, %d: %lld\n", i, j, r);
			if(better(r, c2, c3)) best = r, b2 = c2, b3 = c3;
		}
}


ld mn = 100;
void f(int c2, int c3) {
	if(c2 == 0 && c3 == 0) return;
	if(abs(c2 - c3 * l3) < 1e-3) printf("%d %d\n", c2, c3);
	mn = min(mn, abs(c2 - c3 * l3));
}

int main() {
	int i, j;
	//for(i = -4000; i <= 4000; i++)
	//	for(j = -4000; j <= 4000; j++)
	//		f(i, j);
	//cout << setprecision(20) << mn;
	scanf("%d", &n);
	bool any = false;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			scanf(" %c", &g[i][j]);
			if(g[i][j] != '0') any = true;
		}
	if(!any) { puts("0"); return 0; }
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			for(int d = 0; d < 8; d++)
				dfs(i, j, d);
	go(0); go(4);
	best = 1;
	for(i = 0; i < b2; i++) best = mod(best * 2ll);
	for(i = 0; i < b3; i++) best = mod(best * 3ll);
	printf("%d\n", (int) best);
}