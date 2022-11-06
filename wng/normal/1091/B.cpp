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

int main(){
	DRI(n);
	VPII o(n);
	VPII c(n);
	set<PII> so;
	REP(i,n){
		DRII(x,y);
		o[i]={x,y};
	}
	REP(i,n){
		DRII(x,y);
		c[i]={x,y};
		so.insert(c[i]);
	}
	REP(i,n){
		int tx=o[0].F+c[i].F;
		int ty=o[0].S+c[i].S;
		set<PII> sso;
		sso=so;
		sso.erase(c[i]);
		bool isok=true;
		REPP(j,1,n){
			PII tf={tx-o[j].F,ty-o[j].S};
			if (sso.find(tf)!=sso.end()){
				sso.erase(tf);
			}
			else {isok=false; break;}
		}
		if (isok) {printf("%d %d\n",tx,ty); return 0;}
	}
	cout<<"error"<<endl;
}