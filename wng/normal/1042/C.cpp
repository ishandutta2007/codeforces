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
	DRI(n);
	VI a(n);
	VI ip,iz,ig;
	int mn=-1000000009;
	int imn=-1;
	REP(i,n) {RI(a[i]);
		if (!a[i]) iz.PB(i+1);
		if (a[i]>0) ip.PB(i+1);
		if (a[i]<0) {ig.PB(i+1); if (a[i]>mn) {mn=a[i]; imn=i+1;}}
		}
	if (ig.size()%2) {
			iz.PB(imn);
		}
	
	//cout<<imn<<" "<<iz.size()<<endl;
	VI done(n+1);
	REP(i,(int)iz.size()-1){
		printf("1 %d %d\n",iz[i],iz[i+1]);
	}
	if (iz.size()==n) return 0;
	if (iz.size()) {printf("2 %d\n",iz[iz.size()-1]);}
	for (auto i:iz){ done[i]=1;}
	VI left;
	REPP(i,1,done.size()) { if (!done[i]) {left.PB(i);} }
	REP(i,(int)left.size()-1){
		printf("1 %d %d\n",left[i],left[i+1]);
	}
}