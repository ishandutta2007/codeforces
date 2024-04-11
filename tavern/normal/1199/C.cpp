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
const int maxn = 4e5 + 5;

int n;
ll I;
int a[maxn], lg[maxn], b[maxn], vis[maxn];

bool check(int md){
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	FOR(i, 0, n - md) ++vis[b[i]], cnt += (vis[b[i]] == 1);
	REP(i, 0, md){
		if(1ll * lg[cnt] * n <= I * 8) return true;
		--vis[b[i]];
		if(!vis[b[i]]) --cnt;
		++vis[b[n - md + i]];
		if(vis[b[n - md + i]] == 1) ++cnt;
	}
	return false;
}

int main(){
	scanf("%d%lld", &n, &I);
	//printf("%lld\n", I);
	map<int, int> mp;
	FOR(i, 0, n) scanf("%d", a + i), mp[a[i]] = 1;
	int sz = 0;
	sort(a, a + n);
	for(map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) it -> snd = sz++;
	FOR(i, 0, n) b[i] = mp[a[i]];
	lg[1] = 0;
	REP(i, 1, n) lg[i] = lg[i - 1] + ((1 << lg[i - 1]) < i);
	int lb = -1, rb = n + 1;
	for(; lb + 1 < rb; ){
		int md = lb + rb >> 1;
		if(check(md)) rb = md;
		else lb = md;
	}
	printf("%d\n", rb);
	return 0;
}