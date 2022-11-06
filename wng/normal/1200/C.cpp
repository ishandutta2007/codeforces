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
	LL n,m; int q;
	scanf("%lld %lld %d",&n,&m,&q);
	LL g=__gcd(n,m);
	LL sec1ev=n/g;
	LL sec2ev=m/g;
	REP(i,q){
		int sx,sy; LL ex,ey;
		scanf("%d %lld %d %lld",&sx,&ex,&sy,&ey);
		LL s1,s2;
		if (sx==1){s1 = (ex-1)/sec1ev;} 
		else {s1= (ex-1)/sec2ev;}
		if (sy==1){s2 = (ey-1)/sec1ev;} 
		else {s2= (ey-1)/sec2ev;}
		if (s1==s2) {printf("YES\n");}
		else {printf("NO\n");}
	}
}