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

int n, m;
int dir[100][100];
char g[100][100];
//int memo[100][100];
//int solve(int i, int j) {
//	int &r = memo[i][j];
//	if(r != -1) return r;
//	if(i >= n || j >= m) return r = 0;
//	r = solve(i + 1, j) + solve(i, j + 1) - solve(i + 1, j + 1);
//	int mn = INT_MAX;
//	for(int k = i; k < n && mn > 0; k++) {
//		mn = min(mn, dir[k][j]);
//		//printf("solve(%d, %d) line %d += %d\n", i, j, k, mn);
//		r += mn;
//	}
//	debug("solve(%d, %d) = %d\n", i, j, r);
//	return r;
//}

int memo[41][41][41][41];
inline int solve(int a, int b, int c, int d) {
	if(a > c || b > d) return 0;
	return memo[a][b][c][d];
}

int main() {
	int i, j, q, a, b, c, d;
	scanf("%d %d %d", &n, &m, &q);
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			scanf(" %c", &g[i][j]);
	for(i = 0; i < n; i++)
		for(j = m - 1; j >= 0; j--)
			if(g[i][j] == '0') dir[i][j] = dir[i][j + 1] + 1;
			else dir[i][j] = 0;
	for(a = n - 1; a >= 0; a--)
		for(b = m - 1; b >= 0; b--)
			for(c = a; c < n; c++)
				for(d = b; d < m; d++) {
					int &r = memo[a][b][c][d];
					r = solve(a, b + 1, c, d) + solve(a + 1, b, c, d) - solve(a + 1, b + 1, c, d);
					int mn = d - b + 1;
					for(int i = a; i <= c && mn > 0; i++) {
						mn = min(mn, dir[i][b]);
						r += mn;
					}

				}
	for(i = 0; i < q; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d); a--; b--; c--; d--;
		printf("%d\n", solve(a, b, c, d));
		//printf("%d\n", solve(a, b) - solve(c + 1, b) - solve(a, d + 1) + solve(c + 1, d + 1));
	}
}