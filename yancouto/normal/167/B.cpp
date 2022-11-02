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

const int N = 212;

int a[N], p[N];

int seen[N][N][N];
double memo[N][N][N];
int l, n;
double solve(int i, int bg, int won) {
	if(bg > 200) bg = 200;
	if(i == n) return won >= l && bg >= won;
	double &r = memo[i][bg][won];
	if(seen[i][bg][won]) return r;
	seen[i][bg][won] = true;
	r = solve(i + 1, bg, won) * ((100. - p[i]) / 100.) +
	    solve(i + 1, bg + a[i] + 1, won + 1) * (p[i] / 100.);
	return r;
}

int main() {
	int i, j, k;
	scanf("%d %d %d", &n, &l, &k);
	for(i = 0; i < n; i++)
		scanf("%d", &p[i]);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%.10f\n", solve(0, k, 0));
}