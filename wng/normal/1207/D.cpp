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

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}


int main(){
    DRI(n);
    map<int,int> m0,m1;
    map<PII,int> m2;
    int mod=998244353;
    VL fact(n+1);
    VL factinv(n+1);
    fact[0]=1;
    factinv[0]=1;
    REPP(i,1,n+1){
        fact[i]=(fact[i-1]*i)%mod;
        //factinv[i]=modpow(fact[i],mod-2,mod))%mod;
    }
    REP(i,n){
        DRII(x,y);
        m0[x]++;
        m1[y]++;
        m2[{x,y}]++;
    }

    LL nb0=1;
    for (auto it: m0){
        nb0=(nb0*fact[it.S])%mod;
    }
    LL nb1=1;
    for (auto it: m1){
        nb1=(nb1*fact[it.S])%mod;
    }
    LL nb2=1;
    int prev1=-2;
    for (auto it: m2){
        if (it.F.S<prev1) {nb2=0;}
        prev1=it.F.S;
        nb2=(nb2*fact[it.S])%mod;
    }
    LL res=((fact[n]-(nb0+nb1-nb2))%mod + mod)%mod;
   //cout<<fact[n]<<" "<<nb0<<" "<<nb1<<" "<<nb2<<endl;
    printf("%lld\n",res);

}