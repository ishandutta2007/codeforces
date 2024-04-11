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
	DRII(n,h);
	VPII a(n);
	REP(i,n){
		DRII(x,y);
		a[i]={x,y};
	}
	int p0=0;
	int p1=0;
	LL left=h;
	LL res=0;
	while (p1<n-1 and a[p1+1].F-a[p1].S<left){
		left-=a[p1+1].F-a[p1].S;
		p1++;
	}
	res=max(res,a[p1].S+left-a[p0].F);
	//cout<<p0<<" "<<p1<<" "<<res<<endl;
	while (++p0<n){
		left+=a[p0].F-a[p0-1].S;
		while (p1<n-1 and a[p1+1].F-a[p1].S<left){
			left-=a[p1+1].F-a[p1].S;
			p1++;
		}
		res=max(res,a[p1].S+left-a[p0].F);
		//cout<<p0<<" "<<p1<<" "<<res<<endl;
	}
	printf("%I64d\n",res);
}