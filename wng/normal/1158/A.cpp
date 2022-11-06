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
	DRII(n,m);
	VL b(n);
	VL g(m);
	LL ming=1000000000;
	map<LL,int> cb;
	LL sb=0;
	REP(i,n){
		scanf("%I64d",&(b[i]));
		cb[b[i]]++;
		sb+=b[i];
	}
	sort(b.begin(),b.end());
	LL sg=0;
	LL tr=0;
	bool isok=true;
	REP(i,m){
		scanf("%I64d",&(g[i]));
		sg+=g[i];
		ming=min(ming,g[i]);
		if (g[i]<b[n-1]) {isok=false;break;}
		tr+=b[n-1];
	}
	if (ming>b[n-1]) sg+=b[n-1]-b[n-2];
	if (isok) printf("%I64d\n",sb*m+sg-tr);
	else printf("-1\n");
}