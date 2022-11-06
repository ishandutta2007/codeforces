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

pair<int, pair<int, int> > bezout(int a, int b) {
    int x = 1, y = 0;
    int xLast = 0, yLast = 1;
    int q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}

 mul_inv(int a, int b) {
    pair<int, pair<int, int> > r= bezout(a,b);
    if (r.F==1) {return r.S.F;}
    return 0;
}



const int mod = 998244353 ;
int main(){
	DRI(n);
	vector<LL> fi(n+1);
	fi[0]=1;
	REP(i,n){
		fi[i+1]=(fi[i]*(i+1))%mod;
	}
	vector<LL> cni(n+1);
	cni[0]=1;
	REP(i,n){
		cni[i+1]=(((cni[i]*(n-i))%mod)*((mul_inv(i+1,mod)+mod)%mod))%mod;
	}
	//for (auto i:fi) {cout<<i<<" ";}cout<<endl;
	//for (auto i:cni) {cout<<i<<" ";}cout<<endl;
	//OK j'ai fact n de mecs
	LL res=fi[n];
	REP(i,n-1){
		LL ta=(((fi[i]*cni[i])%mod) * (n-i-1)%mod);
		res+=((ta*i)%mod+mod)%mod;
		//cout<<ta<<" "<<((ta*i)%mod+mod)%mod<<endl;
	}
	res%=mod;
	printf("%I64d\n",res);
	
}