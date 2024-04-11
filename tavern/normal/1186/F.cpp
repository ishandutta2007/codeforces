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
const int maxn = 1e6 + 5;

class Edge{
public:
	int u, v, id;
};

int n, m, ans = 0;
int deg[maxn], ori[maxn];
bool used[maxn];
Edge ed[maxn];

inline bool cmp(const Edge &p, const Edge &q){return max(deg[p.u], deg[p.v]) < max(deg[q.u], deg[q.v]);}

int main(){
	scanf("%d%d", &n, &m);
	FOR(i, 0, m){
		scanf("%d%d", &ed[i].u, &ed[i].v);
		++deg[ed[i].u], ++deg[ed[i].v];
		ed[i].id = i;
	}
	FOR(i, 0, m){
		if(deg[ed[i].u] < deg[ed[i].v])
			swap(ed[i].u, ed[i].v);
	}
	sort(ed, ed + m, cmp);
	REP(i, 1, n)
		ori[i] = deg[i];
	for(int i = m - 1; i >= 0; -- i){
		if(deg[ed[i].u] - 1 >= (ori[ed[i].u] + 1) / 2 && deg[ed[i].v] - 1 >= (ori[ed[i].v] + 1) / 2){
			--deg[ed[i].u];
			--deg[ed[i].v];
			used[i] = 1;
			++ans;
		}
		if(ans >= m - (n + m + 1) / 2)
			break;
	}
	assert(ans >= m - (n + m + 1) / 2);
	printf("%d\n", m - ans);
/*	REP(i, 1, n)
		printf("%d ", ori[i]);
	puts("");
	REP(i, 1, n)
		printf("%d ", deg[i]);
	puts("");
*/	FOR(i, 0, m) if(!used[i])
		printf("%d %d\n", ed[i].u, ed[i].v);
	return 0;
}