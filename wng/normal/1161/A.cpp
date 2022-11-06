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
	// 1 - l un des deux est pas dedans
	// 2 - les deux sont dedans mais la derniere occurence du 2e est avant la 1e occurence du 1er
	// ==> tout nouveau premier 
	DRII(n,k);
	LL res=0;
	VI arethere(n,0);
	int nbt=0;
	VI g(k);
	REP(i,k){
		DRI(x);
		x--;
		g[i]=x;
		if (!(arethere[x]++)) nbt++;
	}
	//case 1
	REP(i,n){
		if (!(arethere[i])) res++;
		if (i and !(arethere[i] and arethere[i-1])) res++;
		if (i<n-1 and !(arethere[i] and arethere[i+1])) res++;
	}
	//res= (LL)n*(n-1) - (LL)(nbt)*(nbt-1);
	//cout<<res<<endl;
	//case 2
	int nnbt=0;
	VI at2(n,0);
	REP(i,k){
		if (!(at2[g[i]]++)) {
			nnbt++;
		}
		if (at2[g[i]]==arethere[g[i]]) //derniere occurence. On eut le prendre en 2 !
		{
		    if (g[i] and arethere[g[i]-1] and (not at2[g[i]-1])) res++;
		    if (g[i]<n-1 and arethere[g[i]+1] and (not at2[g[i]+1])) res++;
			//res+=(nbt-nnbt);//les mecs pas encore apparus peuvent tre le 1.
		}
	}
	printf("%I64d\n",res);
}