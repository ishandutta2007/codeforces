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
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    DRII(n,q);
    VI a(n);
    int rmax=-1;
    int maxnum=-1;
    VPII d;
    VPII dd;
    REP(i,n){
		RI(a[i]);
		if (a[i]>maxnum) {rmax=i;
			if (i) d.PB({maxnum,a[i]});
			}
		else{ if (i) d.PB({maxnum,a[i]});}
		maxnum=max(maxnum,a[i]);
	}
	REPP(i,rmax+1,n){
		dd.PB({maxnum,a[i]});
	}
	REPP(i,0,rmax){
		dd.PB(d[i]);
	}
	//for (auto j:dd) {cout<<"("<<j.F<<","<<j.S<<")"<<endl;}
	//cout<<rmax<<"  "<<dd.size()<<endl;
	REP(i,q){
		LL s;
		scanf("%I64d",&s);
		s--;
		PII res;
		if (s<rmax) {res=d[s];}
		else{
				res={maxnum,min(dd[(s-rmax)%(dd.size())].F,dd[(s-rmax)%(dd.size())].S)};
			}
		printf("%d %d\n",res.F,res.S);
	}
}