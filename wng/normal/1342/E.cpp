#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<n; ___I++) scanf("%d", &(X[___I]))  
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



pair<LL, pair<LL, LL> > bezout(LL a, LL b) {
    LL x = 1, y = 0;
    LL xLast = 0, yLast = 1;
    LL q, r, m, n;
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

LL mul_inv(LL a, LL b) {
    pair<LL, pair<LL, LL> > r= bezout(a,b);
    if (r.F==1) {return r.S.F;}
    else return 0;
}



const int mod =998244353;

LL pm(int n,int k){
    LL res=(k%2)?n:1;
    if (k/2){
        LL r=pm(n,k/2);
        res*=r;
        res%=mod;
        res*=r;
    }
    res%=mod;
    return res;
}


int main(){
    DRII(n,k);
    if (k>=n){
        printf("0\n");
        return 0;
    }
    VL facti(n+1);
    facti[0]=1;
    REPP(i,1,n+1){
        facti[i]=(i*facti[i-1])%mod;
    }
    if (k==0){
        printf("%I64d\n",facti[n]);
        return 0;
    }
    
    k=n-k;
    //stirl2
    LL snk=0;
    REPP(j,1,k+1){
        LL ta=((k-j)%2)?(mod-1):1;
        ta*=pm(j,n-1);
        ta%=mod;
        ta*=pm(facti[j-1],mod-2);
        ta%=mod;
        ta*=pm(facti[k-j],mod-2);
        snk+=ta;
        snk%=mod;
    }
   //cout<<"mon snk"<<snk<<endl;
    REPP(i,1,k+1){
        snk*=(n+1-i);
        snk%=mod;
    }
    snk*=2;
    snk%=mod;
    printf("%I64d\n",snk);
}