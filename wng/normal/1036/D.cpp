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
	VI a(n);
	LL sa=0;
	LL sb=0;
	REP(i,n) {RI(a[i]); sa+=a[i];}
	DRI(m);
	VI b(m);
	REP(i,m) {RI(b[i]); sb+=b[i];}
	if (sa!=sb) {printf("-1\n"); return 0;}
	int ia=0;
	int ib=0;
	int lm=0;
	LL diff=0;
	bool canistop=false;
	while (ia<n or ib<m){
		if (canistop and diff==0) {lm+=1; canistop=false;}
		if (!canistop) {diff+=a[ia]; ia++; canistop=true;}
		if (diff<0) {diff+=a[ia]; ia++;}
		if (diff>0) {diff-=b[ib]; ib++;}
	}
	lm++;
	printf("%d\n",lm);
}