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
	DRII(n,m);
	VI a(n);
	VI b(m);
	VI sa(n+1);
	VI sb(m+1);
	REP(i,n) {RI(a[i]); sa[i+1]=sa[i]+a[i];}
	REP(i,m) {RI(b[i]);sb[i+1]=sb[i]+b[i];}
	//Je mate le nb max de mecs de b qui permettent de faire y pour tout y
	//donc le min y pour tout nombre de gars
	VI miny(m+1,1000000000);
	VI minya(n+1,1000000000);
	miny[0]=0;
	minya[0]=0;
	REP(i,m) {REPP(j,i,m) {miny[j-i+1]=min(miny[j-i+1],sb[j+1]-sb[i]);}}
	REP(i,n) {REPP(j,i,n) {minya[j-i+1]=min(minya[j-i+1],sa[j+1]-sa[i]);}}
	//Then double pointeur
	DRI(x);
	int j=0;
	while (j<n and minya[j+1]<=x) {j++;}
	int i=0;
	int res=0;
	for (;j>0;j--){
		int lim=x/minya[j];
		while (i<m and miny[i+1]<=lim) {i++;}
		res=max(res,i*j);
		//cout<<i<<" "<<j<<" "<<res<<endl;
	}
	printf("%d\n",res);
}