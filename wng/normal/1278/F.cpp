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

LL s(int n,int k){
    LL res=0;
    REP(j,k+1){
        int mp=(k-j)%2;
        if (mp) res-=(C(k,j)*powmod(j,n))%mod;
        else res+=(C(k,j)*powmod(j,n))%mod;
    }
    res*=inv(fact[k]);
    res%=mod;
    return res;
}

int main(){

    vector<VL> ss(5001,VL(5001,0));
    ss[0][0]=1;
    REPP(i,1,5001){
        REPP(j,1,5001){
            ss[i][j]=(ss[i-1][j-1]+ j * ss[i-1][j])%mod;
        }
    }

    DRIII(n,m,k);
    LL invm=inv(m);
    LL rr=0;
    fact=VL(5000+1);
    fact[0]=1;
    REPP(i,1,5000+1){
        fact[i]=(fact[i-1]*i)%mod;
    }
    //S(k,i) for k>=i>=0 
    LL ff=1;
    REP(i,k+1){
        LL ta=(ss[k][i]*powmod(invm,i))%mod;
        ta*=ff;
        ta%=mod;
        ff*=(n-i);
        ff%=mod;
        rr+=ta;
        rr%=mod;
       // if (i%10==0) cout<<i<<endl;
    }
    printf("%I64d\n",rr);
}