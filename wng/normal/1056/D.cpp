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
VI ps;
vector<VI> cs;
VI nbc;


void dfs(int i){
	//cout<<"doing "<<i<<endl;
	visited[i]=1;
	nbc[i]=0;
	for (auto j:cs[i]){
		if (!visited[j]) {dfs(j);
		nbc[i]+=nbc[j];}
	}
	if (!nbc[i]) nbc[i]++;
}

int main(){
	DRI(n);
	nbc=VI(n);
	visited=VI(n);
	cs=vector<VI>(n);
	
	VI r(n-1);
	REP(i,n-1){
		RI(r[i]);
		r[i]--;
		cs[i+1].PB(r[i]);
		cs[r[i]].PB(i+1);
	}
	dfs(0);
	VI nbct(n+1);
	REP(i,n){
		nbct[nbc[i]]++;
	}
	VI A(n+1);
	REPP(i,1,n+1){
		A[i]=A[i-1]+nbct[i];
	}
	int c=0;
	/*for (auto i:visited) {cout<<i<<" ";} cout<<endl;
	for (auto i:nbc) {cout<<i<<" ";} cout<<endl;
	for (auto i:nbct) {cout<<i<<" ";} cout<<endl;
	for (auto i:A) {cout<<i<<" ";} cout<<endl;*/
	REPP(i,1,n+1){
		while (A[c]<i) c++;
		printf("%d%c",c,i==n?'\n':' ');
	}
	
}