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

vector<LL> a;
vector<LL> sum;
int n,k;

bool cani(LL b){ //Only if I know I cannot do "better"
	VPII paths;
	REP(i,n){
		REPP(j,i,n){
			if (((sum[j+1]-sum[i])&b)==b){
				paths.PB({i,j+1});
			}
		}
	}
	vector<vector<bool>> good(n+1,vector<bool>(k+1,false));
	good[0][0]=true;
	for (auto i:paths){
		REP(kk,k){
			/*if (good[i.F][kk]!=-1){
				good[i.S]=max(good[i.S],good[i.F]+1);
			}*/
			good[i.S][kk+1]=good[i.S][kk+1]|good[i.F][kk];
		}
	}
	/*REP(i,n+1){
	    cout<<i<<" :";
	    REP(j,k+1){
	        cout<<good[i][j]<<" ";
	    }
	cout<<endl;
	}*/
	return good[n][k];
}

int main(){
	RII(n,k);
	a.resize(n);
	sum.resize(n+1);
	sum[0]=0;
	REP(i,n){cin>>a[i]; sum[i+1]=sum[i]+a[i];}
	LL bmax=sum[n]/k;
	LL b=(LL)1<<60;
	while (!(b&bmax)) b>>=1;
	LL res=0;
	while (b){
	    //cout<<res+b<<" "<<cani(res+b)<<endl;
		if (cani(res+b)) {
				res+=b;
			}
		b>>=1;
	}
	printf("%I64d\n",res);
}