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
const int maxn = 2e6 + 5;

int n;
int q[12];
int ans[12][12];
int dis[12][12][12][12];
char s[maxn];

void bfs(int x, int y){
	FOR(i, 0, 10){
		FOR(j, 0, 10) dis[x][y][i][j] = -1;
		//dis[x][y][i][i] = 0;
		dis[x][y][i][(i + x) % 10] = 1;
		dis[x][y][i][(i + y) % 10] = 1;
		int tl = 0, hd = 0;
		q[tl++] = (i + x) % 10;
		q[tl++] = (i + y) % 10;
		for(; hd < tl; ++hd){
			int u = q[hd];
			//printf("x = %d y = %d u = %d\n", x, y, u);
			if(!~dis[x][y][i][(u + x) % 10]){
				dis[x][y][i][(u + x) % 10] = dis[x][y][i][u] + 1;
				q[tl++] = (u + x) % 10;
			}
			if(!~dis[x][y][i][(u + y) % 10]){
				dis[x][y][i][(u + y) % 10] = dis[x][y][i][u] + 1;
				q[tl++] = (u + y) % 10;
			}
		}
	}
	return;
}

int main(){
	scanf("%s", &s);
	n = strlen(s);
	FOR(i, 0, n) s[i] -= '0';
	FOR(i, 0, 10) FOR(j, 0, 10){
		bfs(i, j);
		FOR(k, 1, n){
			if(dis[i][j][s[k - 1]][s[k]] == -1){
				ans[i][j] = -1;
				break;
			}
			ans[i][j] += dis[i][j][s[k - 1]][s[k]] - 1;
		}
	}
/*	FOR(i, 0, 10){
		FOR(j, 0, 10) printf("%d ", dis[1][0][i][j]);
		puts("");
	}
	puts("");
*/	FOR(i, 0, 10){
		FOR(j, 0, 10) printf("%d ", ans[i][j]);
		puts("");
	}
	return 0;
}