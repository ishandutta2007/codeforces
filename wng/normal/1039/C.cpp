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

map<int,int> p;

int findp(int k){
    if (!p[k]) p[k]=k;
	if (p[k]!=k){
		p[k]=findp(p[k]);
	}
	return p[k];
}

void merge(int k, int k2){
	p[findp(k2)]=p[findp(k)];
}

int main(){
	// Ok the plan is
	// separate the problem into small graphs of all edges that share the same difference
	// d between the values of vertice
	// all values of x not taken by d ==> all subset work ( 2**n)
	// otherwise, we look at the graphs drawn by the edges :
	// if all scc are bipartite graphs, nb sol = 2** ( n- number of connected bipartite graphs)
	// otherwise, well that cannot be cause at least 1 solution
	// So just count scc by doing union find and that'll do
	// Je fias plein e union find mais en tt g n vertices donc ca devrait etre bon.
	DRIII(n,m,k);
	vector<LL> c(n);
	int mod=1000000000+7;
	REP(i,n) {scanf("%I64d",&(c[i]));}
	map<LL,VPII> combs;
	VI p2(max(n,k)+1);
	p2[0]=1;
	REP(i,max(n,k)){
		p2[i+1]=(p2[i]<<1)%mod;
	}
	REP(i,m){
		DRII(u,v);
		LL diff=c[u-1]^c[v-1];
		combs[diff].PB({u,v});
	}
	LL res=(((LL)mod+p2[k]-combs.size())*p2[n])%mod;
	//cout<<p2[n]<<" "<<k<<" "<<p2[k]<<" "<<combs.size()<<" "<<(((LL)mod+p2[k]-combs.size())*p2[n])<<" "<<res<<endl;
	for (auto i: combs){
		int nbm=0;
		p.clear();
		//REP(j,n+1) {p[j]=j;}
		for (auto j:i.S){
			if (findp(j.F)!=findp(j.S)){
				merge(j.F,j.S);
				nbm++;
			}
		}
		res+=p2[n-nbm];
		res%=mod;
	}
	printf("%I64d\n",res);
}