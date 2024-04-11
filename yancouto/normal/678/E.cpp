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

int n;
int seen[1 << 18][18];
double memo[1 << 18][18];
double p[20][20];
double solve(int bm, int i) {
	if(bm == (1 << n) - 1) return i == 0;
	double &r = memo[bm][i];
	if(seen[bm][i]) return r;
	seen[bm][i] = 1;
	for(int j = 0; j < n; j++)
		if(!((bm >> j) & 1))
			r = max(r, p[i][j] * solve(bm | (1 << j), i) + p[j][i] * solve(bm | (1 << j), j));
	return r;
}

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%lf", &p[i][j]);
	double ans = 0;
	for(i = 0; i < n; i++) ans = max(ans, solve((1 << i), i));
	printf("%.20f\n", ans);
}