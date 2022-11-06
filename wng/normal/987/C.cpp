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
	int n;
	RI(n);
	VI s(n);
	VI c(n);
	int inf=500000000;
	REP(i,n){RI(s[i]);}
	REP(i,n){RI(c[i]);}
	vector<VI> mc(3,VI(n,inf));
	int res=inf;
	REP(i,n) {
			int m1=inf;
			int m2=inf;
			REP(j,i){
				if (s[j]<s[i]){
					m1=min(m1,mc[0][j]);
					m2=min(m2,mc[1][j]);
				}
			}
			mc[0][i]=c[i];
			mc[1][i]=m1+c[i];
			mc[2][i]=m2+c[i];
			res=min(res,mc[2][i]);
		}
	if (res==inf) {res=-1;}
	printf("%d\n",res);
}