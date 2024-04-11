// orz dxm
#include<bits/stdc++.h>

using namespace std;

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define y0 yORZDXM
#define y1 yORZDXM
#define y2 yORZDXM
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e18 + 7;
const int maxn = 1e5 + 5;

int n;
int a[maxn];
ll dp[maxn][2];

int main(){
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n) FOR(j, 0, 2) dp[i][j] = INF;
	dp[0][0] = 0;
	FOR(i, 0, n) FOR(j, 0, 2) if(dp[i][j] != INF){
		dp[i + 1][j ^ 1] = min(dp[i + 1][j ^ 1], dp[i][j] + abs(-1 - a[i]));
		dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + abs(1 - a[i]));
	}
	printf("%lld\n", dp[n][0]);
	return 0;
}