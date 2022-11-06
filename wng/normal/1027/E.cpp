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
	DRII(n,k);
	int mod=998244353;
	vector<vector<LL>> pf(1,vector<LL>(1,1));
	vector<vector<LL>> nf;
	REPP(i,1,n){
		nf=vector<vector<LL>>(i+1,vector<LL>(i+1,0));
		REP(j,i) {
			REP(kk,j+1){
				nf[max(j,kk+1)][kk+1]+=pf[j][kk];
				nf[j][0]+=pf[j][kk];
			}
		}
		REP(j,i+1){
			REP(kk,j+1){
				nf[j][kk]%=mod;
			}
		}
		pf=nf;
	}
	vector<LL> D(n);
	REP(i,n){
		REP(j,i+1){
			D[i]+=pf[i][j];
		}
		D[i]%=mod;
	}
	
	LL res=0;
	REP(i,n){
		REP(j,n){
			//printf("%d,%d : %d ; %I64d\n",i,j,(i+1)*(j+1),(D[i]*D[j])%mod);
			if ((i+1)*(j+1)<k) {res+=(D[i]*D[j])%mod;}
		}
		res%=mod;
	}
	printf("%I64d\n",(res*2)%mod);
}