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
const int maxn = 1e5 + 5;

int n;
int a[maxn];
ll ans;
vector<pii> vec;

int main(){
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", a + i);
	if(n == 1){
		if(!(a[0] & 1) || (!a[0])) puts("cslnb");
		else puts("sjfnb");
		return 0;
	}
	sort(a, a + n);
	int same = 0;
	FOR(i, 0, n - 1) if(a[i] == a[i + 1])
		++same;
	ll res = 0, emp = 0;
	if(same > 1){
		puts("cslnb");
		return 0;
	}
	else if(same == 1){
		FOR(i, 0, n - 1) if(a[i] == a[i + 1]){
			if((i && a[i] - 1 == a[i - 1]) || a[i] - 1 < 0){
				puts("cslnb");
				return 0;
			}
			else --a[i], ++res;
		}
	}
	for(int i = 0, j = 0; i < n; ){
		for(; j < n && a[j] == a[i] + j - i; ++j);
		vec.PB(MP(a[i], a[j - 1]));
		i = j;
	}
	FOR(i, 0, vec.size()){
		if(!i){
			emp += vec[i].fst - 0;
			res += (vec[i].snd - vec[i].fst + 1) * emp;
		}
		else{
			emp += vec[i].fst - vec[i - 1].snd - 1;
			res += (vec[i].snd - vec[i].fst + 1) * emp;
		}
	}
	if(res & 1) puts("sjfnb");
	else puts("cslnb");
	return 0;
}