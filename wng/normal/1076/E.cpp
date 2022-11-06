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

vector<VI> cs;
vector<VI> ncs;
VI vdfs;
vector<VPII> gs;
vector<LL> st(1<<19,0);
LL vs=0;
int n;
vector<LL> res;

void dfs(int i,int lvl){
	vdfs[i]=1;
	for (auto g:gs[i]){
		//Ajout des valeurs de i
		int x=g.S;
		int d=g.F;
		vs+=x;
		int ii=d+lvl+1;
		while (ii<=n){
			st[ii]+=x;
			ii+=ii&-ii;
		}
	}
	//Determination du resultat pour i
	res[i]=vs;
	int ii=lvl;
	while (ii>0){
		res[i]-=st[ii];
		ii-=ii&-ii;
	}
	//visite des enfants de i
	for (auto j:cs[i]){
		if (!vdfs[j]){
			dfs(j,lvl+1);
		}
	}
	// Enlevage des valeurs ayant pour parent i
	for (auto g:gs[i]){
		int x=g.S;
		int d=g.F;
		vs-=x;
		ii=d+lvl+1;
		while (ii<=n){
			st[ii]-=x;
			ii+=ii&-ii;
		}
	}
}

int main(){
	RI(n);
	res=vector<LL>(n);
	vdfs=VI(n);
	gs=vector<VPII>(n);
	cs=vector<VI>(n);
	vector<VI> ncs(n);
	REP(i,n-1){
		DRII(x,y);
		x--;
		y--;
		cs[x].PB(y);
		cs[y].PB(x);
		
	}
	DRI(q);
	REP(i,q){
		DRIII(v,d,x);
		v--;
		gs[v].PB({d,x});
	}
	dfs(0,0);
	REP(i,n){
		printf("%I64d%c",res[i],i==n-1?'\n':' ');
	}
}