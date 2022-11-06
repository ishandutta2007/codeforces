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
	VI a(n+1);
	VI am(n+1);
	REP(i,n){
		RI(a[i+1]);
		am[a[i+1]]=i+1;
	}
	VI res(n+1,0);
	res[n]=0;
	/*for (auto i: a) { cout<<i<<" ";} cout<<endl;
	for (auto i: am) { cout<<i<<" ";} cout<<endl;/**/
	for (int j=n-1; j>1;j--){
		for (int k=am[j]+j;k<=n;k+=j){
			if (a[k]>j and !res[a[k]]) {res[j]=1; break;}
		}
		if (!res[j]) {
			for (int k=am[j]-j;k>0;k-=j){
				if (a[k]>j and !res[a[k]]) {res[j]=1; break;}
			}
		}
	}
	if (n>1) {res[1]=1;}
/*	for (auto i: res) { cout<<i<<" ";} cout<<endl;/**/
	REPP(i,1,n+1){
		printf("%c",res[a[i]]?'A':'B');
	}
	printf("\n");
}