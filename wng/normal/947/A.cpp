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
	int x2;
	RI(x2);
	vector<int> sieve(x2+1,0);
	REPP(i,2,x2+1){
		if (not sieve[i]) {
				REPP(j,1,x2/i+1) {sieve[j*i]=i;}
			}
	}
	//for (auto i:sieve) {cout<<i<<" ";} cout<<endl;
	int maxdiv=sieve[x2];
	int minx1=x2-maxdiv+1; //le max est x2
//	cout<<minx1<<" "<<maxdiv<<endl;
	if (sieve[x2]==x2) {minx1=x2;}
	int res=x2;
	REPP (i,minx1,x2)
	{
		if (sieve[i]!=i) {int minx0=i-sieve[i]+1; res=min(res,minx0); /*cout<<i<<" is "<<minx0<<" s:"<<sieve[i]<<endl;*/}
		else {res=min(res,i);}
	}
	printf("%d",res);
}