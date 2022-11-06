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
	LL n;
	LL b;
	scanf("%I64d%I64d",&n,&b);
	vector<LL> ps;
	vector<LL> qs;
	int f2=0;
	while (!(b&1)) {f2++; b/=2;}
	if (f2) {ps.PB(2); qs.PB(f2);}
	int tt=3;
	while ((LL)tt*tt<=b){
		int ff=0;
		while (!(b%tt)) {ff++; b/=tt;}
		if (ff) {ps.PB(tt); qs.PB(ff);}
		tt+=2;
	}
	if (b>1) {ps.PB(b); qs.PB(1);}
	bool jadone=false;
	LL sol=0;
	int psize=ps.size();
	REP(i,psize){
		//cout<<i<<" "<<ps[i]<<" "<<qs[i]<<endl;
		LL nbf=0;
		LL p=ps[i];
		LL pp=p;
		while (true){
			nbf+=n/pp;
			if (pp>n/p) break;
			pp*=p;
		}
		if (!jadone){ jadone=true; sol=nbf/qs[i];}
		else {sol=min(sol,nbf/qs[i]);};
	}
	printf("%I64d\n",sol);
}