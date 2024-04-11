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

VI erastocrible(int n) { // generates a table of size n+1 that contains 1 if i is prime else 0
    VI res(n+1,1);
    VI rr;
    res[0]=0;
    res[1]=0;
    if (n<2) return rr;
    for (int i=4;i<n+2;i+=2) res[i]=0;
    rr.PB(2);
    for(int i=3;i<=n;i+=2){
        if (res[i]){
			rr.PB(i);
            int in=3*i;
            int ta=2*i;
            while (in<=n){
                res[in]=0;
                in+=ta;
            }
        }
    }
    return rr;
}

int main(){
	DRI(n);
	VI a(n);
	VI ps=erastocrible(4000);
	VI r(4000);
	map<int,int> otr;
	int gcd;
	REP(i,n) {RI(a[i]); gcd=i?__gcd(gcd,a[i]):a[i];}
	REP(i,n){
		a[i]/=gcd;
		if (a[i]>1){
			for (auto p: ps){
				bool ism=!(a[i]%p);
				bool todo=ism;
				while (ism){
					a[i]/=p;
					ism=!(a[i]%p);
				}
				if (todo) {r[p]++;}
				if (a[i]<p) {break;}
			}
			if (a[i]>1) {otr[a[i]]++;}
			
		}
		}
	int nr=0;
	for (auto i:ps){
		nr=max(nr,r[i]);
	}
	for (auto i:otr){
		nr=max(nr,i.S);
	}
	if (nr) printf("%d\n",n-nr);
	else printf("-1\n");
}