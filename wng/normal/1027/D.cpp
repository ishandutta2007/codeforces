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

VI ving;
VI ved;
VI a;
int k=0;
int numcycle=1;

int visit2(int i){
	ved[i]=k;
	if (ved[a[i]]){
		return k;
	}
	else{
		return visit2(a[i]);
	}
}
int visit(int i){
	ving[i]=1;
	if (ved[a[i]]){
	    ved[i]=-1;
	    ving[i]=0;
	    return ved[i];
	}
	if (ving[a[i]]){
		k++;
		visit2(i);
	    ving[i]=0;
		return k;
	}
	visit(a[i]);
	if (!ved[i]) ved[i]=-1;
	ving[i]=0;
	return ved[i];
}

int main(){
	int inf=100000;
	DRI(n);
	VI c(n);
	a = VI(n);
	VI r(n+1,inf);
	ved= VI(n);
	ving= VI(n);
	REP(i,n) {RI(c[i]);}
	REP(i,n) {RI(a[i]); a[i]--;}
	/*for (auto i: a) {cout<<i<<" ";} cout<<endl;
	for (auto i: c) {cout<<i<<" ";} cout<<endl;*/
	REP(i,n){
		if (!ved[i]){
			visit(i);
		}
	}
	REP(i,n){
		if (~ved[i]){
		r[ved[i]]=min(r[ved[i]],c[i]);}
	}
	/*for (auto i: ved) {cout<<i<<" ";} cout<<endl;
	for (auto i: r) {cout<<i<<" ";} cout<<endl;
	for (auto i: ving) {cout<<i<<" ";} cout<<endl;*/
	LL res=0;
	REPP(i,1,n+1){
		if (r[i]!=inf) {res+=r[i];}
	}
	printf("%I64d\n",res);
}