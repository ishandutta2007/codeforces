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
	VI nb(n,0);
	VI minroll(n,n+1);
	REP(i,m){
		DRII(x,y);
		x--; y--;
		nb[x]++;
		minroll[x]=min(minroll[x],(y-x+n)%n);
	}
	/*REP(i,n){
		cout<<i<<" "<<nb[i]<<" "<<minroll[i]<<endl;
	}*/
	REP(i,n){
		int seconds=0;
		REP(j,n){
			int w=(i+j)%n;
			if (nb[w]){
				seconds=max(seconds,j+(nb[w]-1)*n+minroll[w]);
			}
		}
		printf("%d%c",seconds,i==n-1?'\n':' ');
	}
}