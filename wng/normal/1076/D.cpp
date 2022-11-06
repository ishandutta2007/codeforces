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

VI visited;
vector<VI> ncs;
VI ps,ie;

int visit(int i,int k){
	//cout<<"visiting "<<i<<endl;
	visited[i]=1;
	int res=0;
	if (i) {k--; res++; printf("%d%c",ie[i]+1,k?' ':'\n'); if (!k) return res;}
	for (auto j:ncs[i]){
		if (!visited[j]){
			int td=visit(j,k);
			k-=td;
			res+=td;
			if (!k) break;
		}
	}
	return res;
}

int main(){
	DRIII(n,m,k);
	visited=VI(n,0);
	vector<vector<pair<int,PII>>> cs(n);
	REP(i,m){
			DRIII(u,v,w);
			u--;
			v--;
			cs[u].PB({v,{w,i}});
			cs[v].PB({u,{w,i}});
	}
	ps=VI(n,-1);
	ie=VI(n,-1);
	vector<LL> d1(n,((LL)1)<<50);
	d1[0]=0;
	set<pair<LL,int>> rankd;
	REP (i,n){
		rankd.insert({d1[i],i});
	}
	while (!rankd.empty()){
		int i=rankd.begin()->S;
		LL d=d1[i];
		//cout<<i<<" "<<rankd.size()<<endl;
		rankd.erase({d,i});
		for (auto c:cs[i]){
			if (d1[c.F]>d+c.S.F){
				rankd.erase({d1[c.F],c.F});
				d1[c.F]=d+c.S.F;
				rankd.insert({d1[c.F],c.F});
				ps[c.F]=i;
				ie[c.F]=c.S.S;
			}
		}
	}
	ncs=vector<VI>(n);
	VI nbcs(n);
	REPP(i,1,n){
		ncs[ps[i]].PB(i);
	}
	int tr=min(n-1,k);
	printf("%d\n",tr);
	//cout<<"ahah"<<endl;
	//for (auto t:ncs[0]){ cout<<t<<" ";} cout<<"total :"<<ncs[0].size()<<endl;
	if (tr) visit(0,tr);
	return 0;
}