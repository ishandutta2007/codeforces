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
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define REP(i,x,y) for(int i=(x);i<=(y);++i)
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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF=1e9+7;
const int maxn=1e3+5;

int n,m;
int szRow[maxn],szCol[maxn];
int a[maxn][maxn],ans[maxn][maxn],rkRow[maxn][maxn],rkCol[maxn][maxn];
vector<int> vec;

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,0,n) FOR(j,0,m) scanf("%d",&a[i][j]);
	FOR(i,0,n){
		vec.clear();
		FOR(j,0,m) vec.PB(a[i][j]);
		sort(vec.begin(),vec.end());
		vec.erase(unique(vec.begin(),vec.end()),vec.end());
		szRow[i]=vec.size();
		FOR(j,0,m) rkRow[i][j]=lower_bound(vec.begin(),vec.end(),a[i][j])-vec.begin();
	}
	FOR(j,0,m){
		vec.clear();
		FOR(i,0,n) vec.PB(a[i][j]);
		sort(vec.begin(),vec.end());
		vec.erase(unique(vec.begin(),vec.end()),vec.end());
		szCol[j]=vec.size();
		FOR(i,0,n) rkCol[i][j]=lower_bound(vec.begin(),vec.end(),a[i][j])-vec.begin();
	}
	FOR(i,0,n) FOR(j,0,m){
		if(rkRow[i][j]>rkCol[i][j]){
			ans[i][j]=max(szRow[i],szCol[j]+rkRow[i][j]-rkCol[i][j]);
		}
		else{
			ans[i][j]=max(szCol[j],szRow[i]+rkCol[i][j]-rkRow[i][j]);
		}
	}
	FOR(i,0,n){
		FOR(j,0,m) printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}