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
	VI a(n);
	   vector<vector<LL>> C(1001,vector<LL>(1001,0));
    
    int mod=998244353;
    	
    C[0][0]=1;
    REPP(i,1,1001){
        C[i][0]=1;
        REPP(j,1,i+1){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
	REP(i,n) {RI(a[i]);}
	VI r(1,1);
	LL res=0;
	for (int i=n-1;i>=0;i--){
		LL tp=0;
		if (a[i]>0 and a[i]<(int)r.size()){
			REP(j,(int)r.size()-a[i]){
				tp+=C[r.size()-1-j][a[i]]*r[j];
			    tp%=mod;
			}
		}
		r.PB(tp);
		res+=tp;
	//	cout<<i<<" "<<a[i]<<" "<<tp<<" "<<r.size()<<endl;
	}
	res%=mod;
	printf("%I64d\n",res);
}