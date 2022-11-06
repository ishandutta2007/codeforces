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
	DRIII(n,a,b);
	string s;
	cin>>s;
	VI c(n+1,0);
	REP(i,n){
		//longest substring that is present before :
		int ml=0;
		int tt=1;
		int maxtt=(i+1)/2;
		if (i){
			while ((tt<<1)<=maxtt) {tt<<=1;}
			while (tt){
				if (ml+tt<=maxtt and s.substr(0,i-ml-tt+1).find(s.substr(i-ml-tt+1,ml+tt))<i-ml-tt+1) ml+=tt;
//				cout<<s.substr(0,i-ml-tt+1)<<" "<<ml<<" "<<tt<<" "<<s.substr(i-ml-tt+1,ml+tt)
				tt>>=1;
			}
		}
		if (ml) {c[i+1]=min(c[i+1-ml]+b,c[i]+a);}
		else {c[i+1]=c[i]+a;}
		//cout<<i<<" "<<maxtt<<" "<<ml<<" "<<c[i+1]<<endl;
	}
	printf("%d\n",c[n]);
}