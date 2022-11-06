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

int mod=998244353;

LL powmod(int a, int n){
    LL res=1;
    if (n>1){
    res=powmod(a,n/2);
    res*=res;
    }
    res%=mod;
    res*=(n%2)?a:1;
    res%=mod;
    return res;
}

VL fact;

LL inv(int x){
    return powmod(x,mod-2);
}

LL C(int n,int k){
    return (((fact[n]*inv(fact[k]))%mod)*inv(fact[n-k]))%mod;
}

int main(){
    DRII(n,k);
    VI h(n);
    fact=VL(n+1);
    fact[0]=1;
    REPP(i,1,n+1){
        fact[i]=(fact[i-1]*i)%mod;
    }
    int ng=0;
   REP(i,n) {RI(h[i]);}
   REP(i,n){
        if (h[i]==h[(i+1)%n]){
            ng++;
        }
    }
    int np=n-ng;
    LL totposs=powmod(k,np);
    LL possegales=0;
    REP(i,np/2+1){
        possegales+=((C(np,i)*C(np-i,i))%mod*powmod(k-2,np-2*i))%mod;
    }
    possegales%=mod;
    LL res=((totposs-possegales)%mod + mod) %mod;
    res *= inv(2);
    res %=mod;
    res *=powmod(k,ng);
    res%=mod;
    printf("%I64d\n",res);
}