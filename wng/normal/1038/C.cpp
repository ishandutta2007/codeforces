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
	VI b(n);
	REP(i,n) {RI(a[i]);}
	REP(i,n) {RI(b[i]);}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int nba=0;
	int nbb=0;
	LL sa=0;
	LL sb=0;
	int tour=0;
	while (nba<n and nbb<n){
		//printf("%d %d %d %d %d ",tour, nba,nbb, a[nba],b[nbb]);
		if (tour%2){
			if (a[nba]<=b[nbb]) {sa+=a[nba];nba++;}
			else {nbb++;}
		}
		else {
			if (a[nba]<=b[nbb]) {nba++;}
			else {sb+=b[nbb];nbb++;}
		}
		//printf("%I64d %I64d\n",sa,sb);
		tour++;
	}
	while (nba<n){
		if (tour%2){
			sa+=a[nba];nba++;
		}
		else {
			nba++;
		}
		tour++;
	}
	while (nbb<n){
		if (tour%2){
			nbb++;
		}
		else {
			sb+=b[nbb];nbb++;
		}
		tour++;
	}	
	printf("%I64d\n",sa-sb);
}