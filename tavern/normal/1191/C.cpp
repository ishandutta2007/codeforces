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

int ans;
ll n, m, k;
ll a[maxn];
set<ll> s;

int count(ll curl, ll curr){
	int ret = 0;
	for(set<ll>::iterator it = s.begin(); it != s.end() && (*it) >= curl && (*it) <= curr; ++ret, ++it);
	return ret;
}

void erase(ll curl, ll curr){
	for(; s.size() && (*s.begin()) >= curl && (*s.begin()) <= curr; s.erase(s.begin()));
	return;
}

int main(){
	scanf("%lld%lld%lld", &n, &m, &k);
	FOR(i, 0, m) scanf("%lld", a + i), s.insert(a[i]);
	ll curl = 1, curr = k;
	while(s.size()){
		int res = count(curl, curr);
		//printf("%lld %lld %d\n", curl, curr, res);
		if(res > 0){
			++ans;
			erase(curl, curr);
			curr += res;
		}
		else{
			ll fir = *s.begin();
			ll cnt = (fir - curr) / k;
			//printf("cnt = %lld\n", cnt);
			curl += (cnt + 1) * k;
			curr += (cnt + 1) * k;
			if(curr - k >= fir){
				curr -= k;
				curl -= k;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}