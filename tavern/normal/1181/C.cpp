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
const int maxn = 1005;
const int logn = 15;

int n, m;
int d[maxn][maxn], r[maxn][maxn], mn[maxn][maxn][logn];
char s[maxn][maxn];
ll ans = 0;

int getMin(int lb, int rb, int j){
	int i = 0;
	for(; lb + (1 << i) - 1 <= rb; ++i);
	--i;
	//printf("lb = %d rb = %d i = %d mn = %d %d\n", lb, rb, i, mn[lb][j][i], mn[rb - (1 << i)][j][i]);
	return min(mn[lb][j][i], mn[rb - (1 << i) + 1][j][i]);
}

int main(){
	scanf("%d%d", &n, &m);
	FOR(i, 0, n)
		scanf("%s", s + i);
	for(int i = n - 1; i >= 0; --i) for(int j = m - 1; j >= 0; --j){
		if(j != m - 1 && s[i][j] == s[i][j + 1])
			r[i][j] = r[i][j + 1] + 1;
		else
			r[i][j] = 1;
		if(i != n - 1 && s[i][j] == s[i + 1][j])
			d[i][j] = d[i + 1][j] + 1;
		else
			d[i][j] = 1;
	}
/*	FOR(i, 0, n){
		FOR(j, 0, m)
			printf("%d ", r[i][j]);
		puts("");
	}
*/	FOR(k, 0, logn) FOR(i, 0, n) FOR(j, 0, m){
		if(!k){
			mn[i][j][k] = r[i][j];
		}
		else{
			if(i + (1 << (k - 1)) < n)
				mn[i][j][k] = min(mn[i][j][k - 1], mn[i + (1 << (k - 1))][j][k - 1]);
			else
				mn[i][j][k] = mn[i][j][k - 1];
		}
	}
	FOR(i, 0, n) FOR(j, 0, m){
		int a, b, c;
		a = i, b = i + d[i][j];
		if(b >= n)
			continue;
		if(d[b][j] == d[a][j])
			c = b + d[b][j];
		else
			continue;
		if(c >= n || d[c][j] < d[i][j])
			continue;
		//printf("a = %d b = %d c = %d j = %d\n", a, b, c, j);
		int res = getMin(a, c + d[i][j] - 1, j);
		ans += res;
	}
	printf("%lld\n", ans);
	return 0;
}