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
	DRII(n,y1);
	VI a(n);
	VI aok(n,1);
	REP(i,n) {RI(a[i]); }
	DRII(m,y2);
	VI b(m);
	VI bok(m,1);
	REP(i,m) {RI(b[i]);}
	int t=0;
	
	int res=2;
	while (true){
		VI va(2);
		VI vb(2);
		REP(i,n) {if (aok[i]) va[(a[i]>>t)%2]++;}
		REP(i,m) {if (bok[i]) vb[(b[i]>>t)%2]++;}
		res=max(res,max(va[0]+vb[1],va[1]+vb[0]));
		if (va[0]+vb[0]>res) {
			REP(i,n) {if (aok[i] and ((a[i]>>t)%2)) aok[i]=0;}
			REP(i,m) {if (bok[i] and ((b[i]>>t)%2)) bok[i]=0;}
		}
		else {if (va[1]+vb[1]>res) {
			REP(i,n) {if (aok[i] and !((a[i]>>t)%2)) aok[i]=0;}
			REP(i,m) {if (bok[i] and !((b[i]>>t)%2)) bok[i]=0;}
		}
		else break;
		}
		t++;
		if (t>29) break;
	}
	printf("%d\n",res);
}