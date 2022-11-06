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
	VI a(1001,0);
	VPII res;
	REP(i,n-1){
		DRII(x,y);
		if (x>y) {swap(x,y);}
		if (y!=n or x==n) {printf("NO\n"); return 0;}
		a[x]++;
	}
	int freegift=n-1;
	while (a[freegift]) freegift--;
	int stsearch=n;
	while ((int)res.size()<n-1){
		stsearch--;
		int mintosearch=freegift+1;
		while (!a[stsearch]) {stsearch--;}
		if (stsearch<mintosearch) {printf("NO\n"); return 0;}
		VI chain(1,n);
		while ((int)chain.size()<a[stsearch]) {
			chain.PB(freegift);
			if (!freegift) {printf("NO\n"); return 0;}
			freegift--;
			while (a[freegift]) freegift--;
		}
		chain.PB(stsearch);
		REP(i,(int)chain.size()-1){
			res.PB({chain[i],chain[i+1]});
		}
	}
	printf("YES\n");
	for (auto i:res){
		printf("%d %d\n",i.F,i.S);
	}
}