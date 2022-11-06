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

vector<set<int>> cs;

VI ps;

VI ved;
VI ving;
VI L;


int findp(int i){
	if (ps[i]!=i) ps[i]=findp(ps[i]);
	return ps[i];
}

void merge(int i,int j){
	ps[findp(i)]=findp(j);
}


bool dfs(int i){
	ving[i]=1;
	bool tr=true;
	for (auto c:cs[i]){
		if (ving[c]) {return false;}
		if (!ved[c]) {tr&=dfs(c);}
	}
	ving[i]=0;
	ved[i]=true;
	L.PB(i);
	return tr;
}


int main(){
	DRII(n,m);
	int p=n+m;
	cs=vector<set<int>>(p);
	ved=VI(p);
	ving=VI(p);
	ps=VI(p);
	REP(i,p) ps[i]=i;
	VPII cst(0);
	VI res(p);
	REP(i,n){
		char line[1010];
		RS(line);
		REP(j,m){
			if (line[j]=='=') {merge(i,n+j);}
			if (line[j]=='>') {cst.PB({i,n+j});}
			if (line[j]=='<'){cst.PB({n+j,i});}
		}
	}
	REP(i,p){findp(i);}
	for (auto c:cst){
		cs[ps[c.F]].insert(ps[c.S]);
	}
	bool isok=true;
	REP(i,p){
		if (!ved[ps[i]]){
			if (!dfs(ps[i])) {isok=false; break;}
		}
	}
	//for (auto i:L) {cout<<i<<" ";} cout<<endl;
	//reverse(L.begin(),L.end());
	for (auto i:L) {int maxb=0; for (auto c:cs[i]) {maxb=max(maxb,res[c]);} res[i]=maxb+1;}
	
	if (!isok) {printf("No\n");}
	else{
		printf("Yes\n");
		REP(i,n){ printf("%d%c",res[ps[i]],i==n-1?'\n':' ');}
		REP(i,m){ printf("%d%c",res[ps[i+n]],i==m-1?'\n':' ');}
	}
}