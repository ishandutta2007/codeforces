#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second

using namespace std;
int mod=1000000007;
int main(){
	DRI(n);
	VPII x0(n),x1(n),y0(n),y1(n);
	REP(i,n){
		DRII(a,b);
		DRII(c,d);
		x0[i]={a,i};
		y0[i]={b,i};
		x1[i]={c,i};
		y1[i]={d,i};
	}
	sort(x0.rbegin(),x0.rend());
	sort(y0.rbegin(),y0.rend());
	sort(x1.begin(),x1.end());
	sort(y1.begin(),y1.end());
	//OK maintenant plein de cases:
	if (x0[0].F<=x1[0].F and y0[0].F<=y1[0].F){
		printf("%d %d\n",x0[0].F,y0[0].F); return 0;
	}
	if (x0[0].F<=x1[0].F){
		if (y1[1].F>=y0[0].F) {printf("%d %d\n",x0[0].F,y0[0].F); return 0; }
		if (y0[1].F<=y1[0].F) {printf("%d %d\n",x0[0].F,y1[0].F); return 0; }
	}
	if (y0[0].F<=y1[0].F){
		if (x1[1].F>=x0[0].F) {printf("%d %d\n",x0[0].F,y0[0].F); return 0; }
		if (x0[1].F<=x1[0].F) {printf("%d %d\n",x1[0].F,y0[0].F); return 0; }
	}
	set<int> cds;
	cds.insert(x0[0].S);
	cds.insert(y0[0].S);
	cds.insert(x1[0].S);
	cds.insert(y1[0].S);
	for (auto i:cds){
		int ix0=0;
		int ix1=0;
		int iy0=0;
		int iy1=0;
		while (x0[ix0].S==i) ix0++;
		while (x1[ix1].S==i) ix1++;
		while (y0[iy0].S==i) iy0++;
		while (y1[iy1].S==i) iy1++;
		if (x0[ix0].F<=x1[ix1].F and y0[iy0].F<=y1[iy1].F) {
			printf("%d %d\n",x0[ix0].F,y0[iy0].F); return 0;
		}
	}
	printf("FAILURE\n");
}