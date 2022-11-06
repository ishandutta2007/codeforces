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
VI visited;
VI mxeven; // max number removable to keep things ok
int n;
bool possible=true;

void nbs(int i){
	visited[i]=1;
	int nbodd=0;
	int nbeven=0;
	for (auto c:cs[i]){
		if (!visited[c]){
			nbs(c);
			visited[i]+=visited[c];
			if (visited[c]%2){nbodd++;}
			else {nbeven++;}
			mxeven[i]+=mxeven[c];
		}
	}
	mxeven[i]+=nbeven;
//	cout<<i<<" "<<visited[i]<<" "<<mxeven[i]<<" "<<nbeven<<" "<<nbodd<<endl;
}

int main(){
	RI(n);
	cs.resize(n+1);
	mxeven.resize(n+1);
	visited.resize(n+1);
	REP(i,n-1){
		int a,b;
		RII(a,b);
		cs[a].PB(b);
		cs[b].PB(a);
	}
	nbs(1);
//	for (auto i:visited) {cout<<i<<" ";} cout<<endl;
//	for (auto i:mxeven) {cout<<i<<" ";} cout<<endl;
	if (!(visited[1]%2)){
	    printf("%d\n",mxeven[1]);
	}
	else {
	    printf("-1\n");   
	}
	
}