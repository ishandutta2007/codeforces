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

int pgcd (int m, int n)
{
  return (n==0)?(m):(pgcd( n, m % n));
}

int main(){
	int n;
	VI x;
	RI(n);
	REP(i,n) {int a; RI(a); x.PB(a);}
	vector<int> d;
	sort(x.begin(),x.end());
//	cout<<n<<endl;
//	REP(i,n) {cout<<x[i]<<" ";} cout<<endl;
	REPP(i,1,n) {d.PB(x[i]-x[i-1]);}
	int p=d[0];
	REPP(i,1,n-1) {p=pgcd(p,d[i]);}
	int res=0;
	REP(i,n-1) {res+=d[i]/p-1;}
//	cout<<p<<endl;
//	for(auto i: d) {cout<<i<<" ";} cout<<endl;
	printf("%d",res);
}