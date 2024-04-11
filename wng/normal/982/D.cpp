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

VI parents;
VI nbp;

VI periodes(100001,0);
int periodediff=0;
int tailleperiode=0;
set<int> pds;

int findp(int x){
	if (parents[x]!=x) parents[x]=findp(parents[parents[x]]);
	return parents[x];
}

int merge(int u,int v){
	int pu=findp(u);
	int pv=findp(v);
	periodes[nbp[pu]]-=1;
	if (!periodes[nbp[pu]]){
		pds.erase(nbp[pu]);
	}	
	periodes[nbp[pv]]-=1;
	if (!periodes[nbp[pv]]){
		pds.erase(nbp[pv]);
	}
	periodes[nbp[pv]+nbp[pu]]+=1;
	if (periodes[nbp[pv]+nbp[pu]]==1){
	    pds.insert(nbp[pv]+nbp[pu]);
	}
	nbp[pu]+=nbp[pv];
	nbp[pv]=0;
	parents[pv]=pu;
	return pu;
}

int main(){
	int n;
	int mx=0;
	int res=0;
	RI(n);
	VI a(n+2);
	VPII b;
	nbp.resize(n+2);
	REP(i,n) {RI(a[i+1]); b.PB({a[i+1],i+1});}
	sort(b.begin(),b.end());
	parents.resize(n+2);
	int k=0;
	for (auto p:b){
		int v=p.S;
	    parents[v]=v;
	    periodes[1]+=1;
	    nbp[v]=1;
	    if (periodes[1]==1){
    		periodediff+=1;
    		if (periodediff==1) pds.insert(1);
	    }
		if (parents[v-1]){
			merge(v-1,v);
			}
		if  (parents[v+1]){
			merge(v,v+1);
		}
		k++;
		if (pds.size()==1) {
		        int nr=k/(*pds.begin());
				if (nr>mx){
					mx=nr;
					res=p.F+1;
				}
			}
		//cout<<v<<" "<<pds.size()<<" "<<*pds.begin()<<" "<<findp(v)<<" "<<res<<" "<<mx<<endl;
	}
	printf("%d\n",res);
}