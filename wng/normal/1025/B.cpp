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

LL pgcd (LL m, LL n)
{
  return (n==0)?(m):(pgcd( n, m % n));
}

VI erastocrible(int n) { // generates a table of size n+1 that contains 1 if i is prime else 0
    VI res(n+1,1);
    VI rr;
    res[0]=0;
    res[1]=0;
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
	LL res;
	VI ps=erastocrible(100000);
	set<int> totry;
	REP(i,n){
		DRII(a,b);
		LL c=pgcd(a,b);
		LL ppcm=(LL)((LL)a/c)*b;
		if (!i) {res=ppcm;
		    int tt=a;
		    for (auto j:ps) {
		        if (!(tt%j)) {
		            totry.insert(j);
		            while (!tt%j) {tt/=j;}
		            if (j*j>tt) break;
		        }
		    }
		    if (tt>1) totry.insert(tt);
		    tt=b;
		    for (auto j:ps) {
		        if (!(tt%j)) {
		            totry.insert(j);
		            while (!tt%j) {tt/=j;}
		            if (j*j>tt) break;
		        }
		    }
		    if (tt>1) totry.insert(tt);
		}
		else {res=pgcd(ppcm,res);}
	}
	if (res==1) {printf("-1\n");}
	else {
		LL rr=res;
		for (auto i:totry){
			if (!(res%i)) { rr=i; break;}
		}
		printf("%I64d\n",rr);
	}
}