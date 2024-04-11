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
	DRI(t);
	REP(i,t){
		int maxd=0;
		DRI(n);
		int tt=1;
		while (tt<n){
			VI zero(0);
			VI un(0);
			REP(i,n){
				if (i&tt) { un.PB(i+1);}
				else zero.PB(i+1);
			}
			if ((int)zero.size() and (int)un.size()){
				printf("%d %d", zero.size(),un.size());
				for (auto i:zero) {printf(" %d",i);}
				for (auto i:un) {printf(" %d",i);}
				printf("\n");
				fflush(stdout);
				DRI(x);
				assert(x+1);
				maxd=max(maxd,x);
			}
			tt<<=1;
		}
		printf("-1 %d\n",maxd);
		fflush(stdout);
	}
}