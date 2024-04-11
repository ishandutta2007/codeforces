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
	int n,u;
	RII(n,u);
	VI e;
	REP(i,n) {int a; RI(a); e.PB(a);}
	int st,en;
	st=0;
	en=2;
	double res=-1;
	while (en<n) {
		while (en+1<n and e[en+1]-e[st]<=u) {en++;}
		if (en>=st+2 and e[en]-e[st]<=u) {res=max(res,(e[en]-e[st+1])/(1.0*(e[en]-e[st])));}
	//	cout<<st<<" "<<en<<" "<<res<<endl;
		st++;
		en=max(en,st+2);
		}
	if (res>=0){
	printf("%.10f",res);}
	else
	{cout<<"-1\n";}
}