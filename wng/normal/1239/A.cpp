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


int modulo(int a, int b, int n){
    long long x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}


int mod = 1000000007;
int lim = 100001;
int main(){
	DRII(n,m);
	VI fn(lim);
	VI fm(lim);
	fn[0]=1;
	fm[0]=1;
	REPP(i,1,lim){
		fn[i] = ((LL)fn[i-1]*i)%mod;
		fm[i] = modulo(fn[i],mod-2,mod);
	}
	LL res=1;
	REPP(np,n/2,n){
		if (np*2>=n){
			LL ta=fn[np];
			ta *= fm[n-np];
			ta%=mod;
			ta *= fm[2*np-n];
			ta%=mod;
		    res+=ta;
		}
	}
	REPP(mp,m/2,m){
		if (mp*2>=m){
			LL ta=fn[mp];
			ta *= fm[m-mp];
			ta%=mod;
			ta *= fm[2*mp-m];
			ta%=mod;
		    res+=ta;
		}
	}
	cout<<(res*2)%mod<<endl;
	
}