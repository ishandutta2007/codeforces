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
	LL t;
	scanf("%I64d",&t);
	vector<LL> a(n),b(n);
	VI x(n);
	bool isok=true;
	REP(i,n) {scanf("%I64d",&(a[i]));}
	REP(i,n) {
		scanf("%d",&(x[i]));
		if (i and x[i]<x[i-1]) {isok=false;}
	}
	if (x[n-1]!=n) isok=false;
	//change of plan
	int i=0;
	while (isok and i<n)
	{
		int tp=0;
		REPP(j,i,x[i]){
			tp++;
			if (x[j]!=x[i]) {isok=false; break;}
			b[j]=(j==x[i]-1)?(tp==1?a[j]+t:a[j]+t+1):a[j+1]+t;
		}
		if (tp>1 and x[i]<n and (a[x[i]]-a[x[i]-1])<2) isok=false;
		if (i>=x[i]) {isok=false; break;}
		i=x[i];
	}
	if (!isok) {printf("No\n"); return 0;}
	printf("Yes\n");
	REP(i,n){
		printf("%I64d%c",b[i],i==n-1?'\n':' ');
	}
	}