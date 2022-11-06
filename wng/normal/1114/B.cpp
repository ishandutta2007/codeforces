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
	DRIII(n,m,k);
	VPII a(n);
	VPII b(n);
	
	
	REP(i,n){ DRI(x); a[i]={x,i}; b[i]=a[i];}
	sort(a.rbegin(),a.rend());
	int rank=m*k-1;
	LL mys=0;
	PII upto=a[rank];
	//cout<<rank<<" "<<upto.F<<" "<<upto.S<<endl;
	int counter=0;
	VI spl;
	REP(i,n){
		if (b[i]>=upto) {counter++; mys+=b[i].F;}
		if (counter==m){
			//cout<<i<<" "<<b[i].F<<" "<<b[i].S<<endl;
			spl.PB(i+1);
			counter=0;
		}
	}
	printf("%I64d\n",mys);
	REP(i,k-1){
		printf("%d%c",spl[i],i==k-2?'\n':' ');
	}
	
}