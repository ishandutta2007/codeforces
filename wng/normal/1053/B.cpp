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
	vector<LL> a(n);
	VI b(n);
	VI sb(n+1);
	REP(i,n){scanf("%I64d",&(a[i]));
		LL x=a[i];
		while (x) { 
			if (x&1) b[i]++; 
			x>>=1;
			}
		sb[i+1]=sb[i]+b[i];
		}
	int nbpair=0;
	int nbimp=0;
	LL res=0;
	REP(i,n){
		if (i>=64){ 
			if (sb[i-64]%2) {nbimp++;}
			else {nbpair++;}
			if (sb[i+1]%2) {res+=nbimp;}
			else {res+=nbpair;}
	   // cout<<nbpair<<" "<<nbimp<<endl;
		}
		int maxb=0;
		int sb2=0;
		for (int j=i;j>=max(0,i-63);j--){
			maxb=max(maxb,b[j]);
			sb2+=b[j];
			if (2*maxb<=sb2 and (!(sb2%2))) {
				res++;
			}
		}
	}
	//for (auto i:sb) {cout<<i<<" ";} cout<<endl;
	printf("%I64d\n",res);
}