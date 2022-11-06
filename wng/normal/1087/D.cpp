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

int n,m;

vector<VI> cs;
VI visited;
vector<double> res;

void dfs(int i){
	visited[i]=1;
	double totf=0.0;
	VI ctv;
	for (auto j:cs[i]){
		if (!visited[j]) ctv.PB(j);
	}
	if (ctv.size()==0) {totf=1.0;}
	else { 
		if (ctv.size()==1) {dfs(ctv[0]); totf=res[ctv[0]];}
		else {
			for (auto j:ctv){ dfs(j); totf+=res[j];}
		}
	}
	res[i]=totf;
}



int main(){
	RII(n,m);
	visited=VI(n,0);
	cs=vector<VI>(n,VI(0));
	REP(i,n-1){
		DRII(u,v);
		u--;v--;
		cs[u].PB(v);
		cs[v].PB(u);
	}
	int root=0;
	if (n==2) {printf("%d.0\n",m); return 0;}
	if (n>2) {while (cs[root].size()<2) root++;}
	res=vector<double>(n,0.0);
	dfs(root);
	//for (auto i:res) {cout<<i<<" ";} cout<<endl;
	
	printf("%.8f\n",(m/res[root])*2.0);
}