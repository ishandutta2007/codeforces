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
	int n,a,b;
	RIII(n,a,b);
	map<LL,map<int,int>> m;
	REP(i,n){
		int x,vx,vy;
		RIII(x,vx,vy);
		LL d= (LL)a*vx-vy; // distance apres 1 seconde sort of y a un facteur
		if (!m.count(d)) {m[d]=map<int,int>();}
		if (!m[d].count(vx)) {m[d][vx]=0;}
		m[d][vx]++;
	}
	LL res=0;
	for (auto i:m){
		LL sumi=0;
		for (auto j:i.S){sumi+=j.S;}
		for (auto j:i.S){res+=j.S*(sumi-j.S);}
		//On a compte 2 fois ts les couples, mais c ca qu'il faut lol
	}
	printf("%I64d\n",res);
}