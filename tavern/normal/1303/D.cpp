#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int logn = 63;
const int maxm = 1e5 + 5;

int m, ans;
int a[maxm], cnt[logn];
int dp[logn + 5][maxm + logn + 10][2];
ll n;

inline void umin(int &x, int y){ x = min(x, y); return; }

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%lld%d", &n, &m);
		memset(cnt, 0, sizeof(cnt));
		FOR(i, 0, m){
			scanf("%d", a + i);
			FOR(j, 0, logn / 2) if(a[i] == (1 << j))
				++cnt[j];
		}
		REP(i, 0, logn) REP(j, 0, m + logn + 1) FOR(o, 0, 2)
			dp[i][j][o] = INF;
		ans = INF;
		dp[logn][0][0] = 0;
		for(int i = logn; i >= 0; --i) REP(j, 0, m + logn + 1) FOR(o, 0, 2) if(dp[i][j][o] != INF){
//			if(i <= 7)
//				printf("dp(%d %d %d) = %d\n", i - 1, j, o, dp[i][j][o]);
			if(!i){
				if(!j)
					umin(ans, dp[i][j][o]);
				continue;
			}
			int canuse = min(j + (n >> (i - 1) & 1), (ll)cnt[(i - 1)]);
			int nj = j + (n >> (i - 1) & 1) - canuse;
			umin(dp[i - 1][min(nj * 2, m + logn + 5)][cnt[(i - 1)] > canuse], dp[i][j][o] + (cnt[i - 1] > canuse));
			umin(dp[i - 1][min(nj * 2, m + logn + 5)][o], dp[i][j][o] + o);
			if(o && nj){
				--nj;
				umin(dp[i - 1][min(nj * 2, m + logn + 5)][o], dp[i][j][o] + 1);
				umin(dp[i - 1][min(nj * 2, m + logn + 5)][0], dp[i][j][o]);
			}
		}
		if(ans == INF)
			puts("-1");
		else
			printf("%d\n", ans);
	}
	return 0;
}