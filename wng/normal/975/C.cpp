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
	int n,q;
	RII(n,q);
	VI a(n);
	LL tots=0;
	REP(i,n) {RI(a[i]); tots+=a[i];}
	//cout<<tots<<endl;
	vector<LL> sa(n);
	sa[0]=a[0];
	REPP(i,1,n) {sa[i]=(sa[i-1]+a[i]);}
	vector<LL> k(q);
	REP(i,q) {cin>>k[i];}
	vector<LL> sk(q);
	sk[0]=k[0]>=tots?0:k[0];
	REPP(i,1,q) {
		sk[i]=(sk[i-1]+k[i]); 
		if (sk[i]>=tots) {sk[i]=0;}
	}
	//for (auto i:sa){cout<<i<<" ";} cout<<endl;
	for (auto bs:sk) {
		int i=0;
		int pb=1<<18;
	//	cout<<bs<<" "<<pb<<endl;
		while (pb) {
			int tt=i+pb-1;
			if (tt<n and sa[tt]<=bs) {i+=pb;} //will return the first guy alive
			pb>>=1;
	//		cout<<tt<<" "<<sa[(tt)<n?tt:0]<<" "<<i<<" "<<pb<<endl;
			}
		printf("%d\n",n-i);
	}
}