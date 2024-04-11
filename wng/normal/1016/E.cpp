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
	int a,b,sy;
	RIII(sy,a,b);
	sy*=-1;
	set<pair<double,pair<int,int>>> m;
	int n,q;
	RI(n);
	int mr;
	REP(i,n){
		int l,r;
		RII(l,r);
		m.insert({double(l),{1,0}});
		m.insert({double(r),{-1,0}});
		mr=r;
	}
	RI(q);
	REP(i,q){
		int x,y;
		RII(x,y);
		double s,e;
		// a+(x-a)*sy/double(sy+x)
		s=(double)a+(double(x-a)*sy)/(double(sy)+y);
		e=(double)b+(double(x-b)*sy)/(double(sy)+y);
	    m.insert({s,{0,i+1}});
		m.insert({e,{0,-i-1}});		
	}
	int hidden=0;
	vector<pair<double,double>> rr(q);
	vector<double> rrr(q);
	double previous=0;
	double disthidden=0;
	double distot=0;
	for (auto i:m){
	    if (hidden){
			disthidden+=(i.F-previous);
		}
		previous=i.F;
		//cout<<hidden<<" "<<previous<<" "<<" "<<i.F<<" "<<i.S.F<<" "<<i.S.S<<" "<<disthidden<<endl;
		if (!i.S.F){
		    if (i.S.S>0){
		        rr[i.S.S-1]={disthidden,i.F};
		    }
		    else{
		        int ix=-(i.S.S+1);
		        rrr[ix]=(double)(b-a)*(disthidden-rr[ix].F)/(i.F-rr[ix].S);
		        }
		}
		hidden+=i.S.F;
	}
	REP(i,q){
	    printf("%.8f\n",rrr[i]);//,i==q-1?'\n':' ');
	}
}