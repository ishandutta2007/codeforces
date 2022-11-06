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

VPII res(0);

void docolumns(int i){
	int j=0;
	REP(j,n){res.PB({j,i});
	res.PB({n-1-j,m-i-1});}
}
void docolumn(int i){
	int j=0;
	REP(j,n/2){res.PB({j,i});
	res.PB({n-1-j,i});}
	if (n%2) {res.PB({n/2,i});}
}


int main(){
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    RII(n,m);
    // Hypo : c'est toujours possible...
    //Do columns i and n-1-i. Only takes jumps de taille (x,+-(n-1-2*i)))
    // Jump to (0,i+1) ==> takes jump de taille (xx,n-2*i-2) ==> indit)
    // if only 1 column left do it
    REP(j,m/2){
		docolumns(j);
	}
	if (m%2) {docolumn(m/2);}
	REP(i,res.size()){
		printf("%d %d\n",res[i].F+1,res[i].S+1);
	}
}