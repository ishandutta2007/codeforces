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
	int q;
	RI(q);
	vector<LL> stp(60+2,0);
	REP (i,q){
		int t;
		LL k,x;
		RI(t);
		if (t<3){
				scanf("%I64d%I64d",&x,&k);
				LL mb=(LL)1<<60;
				int lvl=60;
				while (!(mb&x)){mb>>=1;lvl--;}
				stp[lvl]+=k;
				if (t==1){stp[lvl+1]-=(k<<1);}
			}
		else
		{
			scanf("%I64d",&x);
			LL mb=(LL)1<<60;
			int lvl=60;
			while (mb>0 and !(mb&x)){mb>>=1;lvl--;}
			
			while (lvl>=0)
				{
					printf("%I64d%c",x,lvl?' ':'\n');
					//cout<<mb<<" "<<lvl<<" "<<stp[lvl]<<endl;
					LL idp=(((x+stp[lvl])%mb+mb)%mb)>>1;
					mb>>=1;
					lvl-=1;
					x=idp+mb;
				}
				
		}
	}
}