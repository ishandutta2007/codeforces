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

int n;
char v[5] = {'a', 'e', 'i', 'o', 'u'};
char table[5][5] = {{'a', 'e', 'i', 'o', 'u'},
					{'e', 'i', 'o', 'u', 'a'},
					{'i', 'o', 'u', 'a', 'e'},
					{'o', 'u', 'a', 'e', 'i'},
					{'u', 'a', 'e', 'i', 'o'}};
vector<vector<char> > ans;

int main(){
	scanf("%d", &n);
	REP(i, 5, n) if(i >= 5 && !(n % i) && n / i >= 5){
		int j = n / i;
		ans.resize(i);
		FOR(k, 0, i)
			ans[k].resize(j);
		FOR(k, 0, 5) FOR(l, 5, j){
			ans[k][l] = v[k];
		}
		FOR(k, 5, i) FOR(l, 0, 5){
			ans[k][l] = v[l];
		}
		FOR(k, 0, 5) FOR(l, 0, 5){
			ans[k][l] = table[k][l];
		}
		FOR(k, 0, i){
			FOR(l, 0, j)
				if(ans[k][l])
					printf("%c", ans[k][l]);
				else
					printf("a");
		}
		return 0;
	}
	puts("-1");
	return 0;
}