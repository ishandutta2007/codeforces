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
    DRII(n,m);
    int nbi=9;
    VI k(1024);
    REP(i,n){
		DRI(x);
		int ta=0;
		REP(j,x){
			DRI(y);
			ta+=1<<(y-1);
		}
		REPP(j,ta,1024){
			if ((j&ta)==ta) k[j]++;
		}
	}
	const int mod=1e9+10;
    VPII b1(1024,{mod,-1});
    vector<pair<LL,PII>> b2(1024,{(LL)2*mod,{-1,-1}});
	REP(i,m){
		DRI(c);
		DRI(x);
		int ta=0;
		REP(j,x){
			DRI(y);
			ta+=1<<(y-1);
		}
		REP(j,1024){
		    pair<LL,PII> z={(LL)b1[j].F+c,{b1[j].S,i}};
			if (b1[j].S!=-1) {b2[ta|j]=min(b2[ta|j],z);
		    //cout<<b1[j].F<<" "<<b1[j].S<<" "<<i<<" "<<c<<" "<<ta<<" "<<j<<" "<<b2[ta|j].F<<" "<<b2[ta|j].S.F<<" "<<b2[ta|j].S.S<<endl;
			}
		}
		b1[ta]=min(b1[ta],{c,i});
	}
	int maxut=-1;
	LL minprice=(LL)2*mod;
	pair<int,LL> r={maxut,-minprice};
	pair<int,int> rr={-1,-1};
	REP(i,1024){
	   //if (b2[i].S.F!=-1) cout<<i<<" "<<k[i]<<" "<<b2[i].S.F<<" "<<b2[i].S.S<<endl;
		if (b2[i].S.F!=-1 and MP(k[i],-b2[i].F)>r){
			r={k[i],-b2[i].F};
			rr=b2[i].S;
		}
	}
	printf("%d %d\n",rr.F+1,rr.S+1);
}