/*----------------by syr----------------*/
/*

         iii                  ii
     rBQBBBBBBE       BBR iBBBBQBBL     XBBBBBBQBBBBB
   iBBQJ    7BBB      BBsSBBr   BBQ      i      cBBB
  rBBU       iBBw     BBBQi     HBBi           KBBi
  BBH         BB5    iBBB       isL          wBB5
 GBB         iBBi    6BB                   iBBB
 BBQ         BQB     BBD                  QBBi
 BBB        BQB     iQBi                1BBv
 sBBg     wBBB      QBB               iBBB
  7BBBBBBBBBi       BBR              wBBBBBBBBBBBBB
     irvi           ii               ii    i i iii
                i5U
               BBB
               BB7
              1BB
      iPBBBBBKBBR    JBR1       rQBO   BR  UBQP  iBBQi
    7BBBGs7sXBBBi     QBBr     gBBE   rBB BB2BB7HBZQBB
   QBBi      sBQ       BBB   iBBB     SQBBR  BBBB  cBQ
  gBQ        BBg        BBB KBBi      MBBH   BBB   BBs
 iBBv       iBBi         QBBBL        BBR   pBB   iBB
 pBB        BBB         iBBBB        iBB    BBL   KBB
 MBB       BBBR        BBB JBBi      DBR   iBQ    BBL
 GBB     7BBBB2      PBBH   BBBi     BQr   DBB   iBB
  BQBXwgBBP BB7    1BBB      BBQ7   1BB    BBc   BBB
   2BBBBw   BB    EBBS        QBBi  HBa   iBB    BB7
*/
#include<bits/stdc++.h>

using namespace std;

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define x0 x0123456789
#define y0 y0123456789
#define x1 x1234567890
#define y1 y1234567890
#define x2 x2345678901
#define y2 y2345678901
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 7;
const int maxn = 2005;

int n, m, ans;
int a[maxn][maxn];
int sr[maxn][maxn], sc[maxn][maxn], resr[maxn][maxn], resc[maxn][maxn];
int br[maxn], bc[maxn], pr[maxn], pc[maxn];
char s[maxn][maxn];

int main(){
	scanf("%d%d", &n, &m);
	REP(i, 1, n) scanf("%s", s[i] + 1);
	REP(i, 1, n) REP(j, 1, n) a[i][j] = (s[i][j] == 'B');
	REP(i, 1, n) REP(j, 1, n) sr[i][j] = sr[i][j - 1] + a[i][j];
	REP(j, 1, n) REP(i, 1, n) sc[i][j] = sc[i - 1][j] + a[i][j];
	REP(i, 1, n - m + 1){
		int res = 0;
		REP(j, 1, n - m + 1){
			if(j == 1) REP(k, 1, j + m - 1){
				res += (sc[i - 1][k] + sc[n][k] - sc[i + m - 1][k] == 0);
			}
			else{
				res -= (sc[i - 1][j - 1] + sc[n][j - 1] - sc[i + m - 1][j - 1] == 0);
				res += (sc[i - 1][j + m - 1] + sc[n][j + m - 1] - sc[i + m - 1][j + m - 1] == 0);
			}
			resc[i][j] = res;
		}
	}
	REP(i, 1, n - m + 1){
		int res = 0;
		REP(j, 1, n - m + 1){
			if(j == 1) REP(k, 1, j + m - 1) res += (sr[k][i - 1] + sr[k][n] - sr[k][i + m - 1] == 0);
			else{
				res -= (sr[j - 1][i - 1] + sr[j - 1][n] - sr[j - 1][i + m - 1] == 0);
				res += (sr[j + m - 1][i - 1] + sr[j + m - 1][n] - sr[j + m - 1][i + m - 1] == 0);
			}
			resr[j][i] = res;
		}
	}
	REP(i, 1, n) pr[i] = pr[i - 1] + (!sr[i][n]);
	REP(i, 1, n) pc[i] = pc[i - 1] + (!sc[n][i]);
	for(int i = n; i; --i) br[i] = br[i + 1] + (!sr[i][n]);
	for(int i = n; i; --i) bc[i] = bc[i + 1] + (!sc[n][i]);
	REP(i, 1, n - m + 1) REP(j, 1, n - m + 1){
		ans = max(ans, resr[i][j] + resc[i][j] + pr[i - 1] + br[i + m] + pc[j - 1] + bc[j + m]);
	}
	printf("%d\n", ans);
	return 0;
}