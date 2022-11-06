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
	vector<VI> cs(n+1);
	VI deg(n+1);
	VI above2;
	REP(i,n-1){
		int a,b;
		RII(a,b);
		deg[a]+=1;
		deg[b]+=1;
		if (deg[a]==3) above2.PB(a);
		if (deg[b]==3) above2.PB(b);
		cs[a].PB(b);
		cs[b].PB(a);
	}
	int res=0;
	VPII paths;
	if (!above2.size()){
		res=1;
		VI p;
		REPP(i,1,n+1){
			if (deg[i]==1){p.PB(i);}
		}
		paths.PB({p[0],p[1]});
	}
	else{
		if (above2.size()==1){
			int center=above2[0];
			VI p;
			REPP(i,1,n+1){
				if (deg[i]==1){paths.PB({center,i});res++;}
			}
		}
	}
	if (res) {
		printf("Yes\n");
		printf("%d\n",res);
		for (auto i:paths){
			printf("%d %d\n",i.F,i.S);
		}
	}
	else {printf("No\n");}
}