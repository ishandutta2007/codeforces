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
	DRII(n,q);
	REP(i,q){
		DRII(x,y);
		LL res;
		if (n%2){
			LL nbb=(LL)n*n/2+1;
			if ((x%2+y%2)%2){
				res=nbb+(LL)(x-1)/2*n+(x%2?0:1)*(n/2)+ (y-1)/2+1;
			}
			else{
				res=(LL)(x-1)/2*n+(x%2?0:1)*(n/2+1)+ (y-1)/2+1;
			}
		}
		else{
			LL nbb=(LL)n*n/2;
			if ((x%2+y%2)%2){
				res=nbb+(LL)(x-1)*n/2+(y-1)/2+1;
			}
			else{
				res=(LL)(x-1)*n/2+(y-1)/2+1;
			}
		}
		printf("%I64d\n",res);
	}
}