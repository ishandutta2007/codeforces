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

int inf=1000123456;
VI s(100001,inf);
int totreq=0;
int n;

int geti(int i){
	if (s[i]==inf) { 
		printf("? %d\n",i);
		fflush(stdout);
		RI(s[i]);
	}
	int ot=(i+(n>>1)-1)%n+1;
	if (s[ot]==inf) { 
		printf("? %d\n",ot);
		fflush(stdout);
		RI(s[ot]);
	}
	return s[i]-s[ot];
}

int main(){
	RI(n);
	int ns2=n>>1;
	if (ns2%2) {printf("! -1\n"); return 0;}
	VI v(ns2+2,inf);
	v[1]=geti(1);
	v[ns2+1]=-v[0];
	if (!v[0]) {printf("! 1\n"); return 0;}
	int st=1;
	int end=ns2+1;
	while (st!=end){
		int mid=(st+end)/2;
		if (v[mid]!=inf){printf("! -1\n"); return 0;}
		v[mid]=geti(mid);
		if (v[mid]==0) {printf("! %d\n",mid); return 0;}
		if ((LL)v[mid]*v[st]<0) {end=mid;}
		else {st=mid;}
	}
	
}