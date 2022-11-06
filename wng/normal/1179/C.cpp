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

VPII st;

int main(){
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    DRII(n,m);
    int mx=max(n,m);
    int vmax=0;
    int VM=1e6;
    VI a(n);
    VI b(m);
    VI t(VM+1,0);
    REP(i,n){
		RI(a[i]);
		vmax=max(vmax,a[i]);
		t[a[i]]--;
	}
    REP(i,m){
		RI(b[i]);
		vmax=max(vmax,b[i]);
		t[b[i]]++;
	}
    int p=1<<21;
    int N=1<<20;
	st=VPII(p+1,{0,0}); //sum subarray, min sum reached within subarray
	REPP(i,1,vmax+1){
		st[N-1+i]={t[i],t[i]};
	}
	for (int i=N-1;i>0;i--){
		int c1=2*i;
		int c2=2*i+1;
		st[i]={st[c1].F+st[c2].F,min(st[c1].S+st[c2].F,st[c2].S)};
	}
	DRI(q);
	REP(j,q){
		DRIII(qi,i,x);
		i--;
		//update
		int tored;
		int toinc;
		if (qi==1){
			toinc=a[i];
			tored=x;
			a[i]=x;
		}
		else {
			tored=b[i];
			toinc=x;
			b[i]=x;
		}
		int kk=N-1+tored;
		st[kk]={st[kk].F-1,st[kk].S-1};
		kk>>=1;
		while (kk){		
			int c1=2*kk;
			int c2=2*kk+1;
			st[kk]={st[c1].F+st[c2].F,min(st[c1].S+st[c2].F,st[c2].S)};
			kk>>=1;
		}
		kk=N-1+toinc;
		st[kk]={st[kk].F+1,st[kk].S+1};
		kk>>=1;
		while (kk){		
			int c1=2*kk;
			int c2=2*kk+1;
			st[kk]={st[c1].F+st[c2].F,min(st[c1].S+st[c2].F,st[c2].S)};
			kk>>=1;
		}
		//desc
		int s=1;
		int tr=0;
		if(st[s].S>=tr) {printf("-1\n");}
		else {
				while (s<N){
					int c1=s*2;
					int c2=c1+1;
					if (st[c2].S<tr) {
						s=c2;
					}
					else{
						s=c1;
						tr-=st[c2].F;
					}
				}
				printf("%d\n",s-N+1);
			}
	}
}