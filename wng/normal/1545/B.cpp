#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define R(X) cin>>(X)
#define RII(X, Y) cin>>(X)>>(Y)
#define RIII(X, Y, Z)  cin>>(X)>>(Y)>>(Z)
#define DRI(X) int (X); cin>>(X)
#define DRII(X, Y) int X, Y; cin>>(X)>>(Y)
#define DRIII(X, Y, Z) int X, Y, Z; cin>>(X)>>(Y)>>(Z)
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<N; ___I++) cin>>(X[___I]) 
#define DRVL(N, X) VL X(N); for (int ___I=0; ___I<N; ___I++) cin>>(X[___I])
#define RS(X) cin>>X
#define DRS(X) string X; cin>>X
#define CASET int ___T, case_n = 1; cin>>___T; while (___T-- > 0)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int>>
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long>>
#define PB push_back
#define F first
#define S second

using namespace std;

LL modpow(LL base, LL exp, LL modulus) {
  base %= modulus;
  LL result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int main(){
    VL fact(200100,1);
    LL mod=998244353;
    int lim=200010;
    REP(i,lim){
        fact[i+1]=((i+1)*fact[i])%mod;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    CASET{
        DRI(n);
        DRS(s);
        int nb1=0;
        int pnb1=0;
        int cv=0;
        int nb0=0;
        REP(i,n){
            if (s[i]=='1') nb1++;
            if (s[i]=='0') {
                nb0++;
                if (nb1!=pnb1 and (nb1^cv)%2){
                    cv++;
                    pnb1=nb1;
                }
            }
        }
        LL res= fact[(nb1-cv)/2+nb0];
        res*=modpow(fact[nb0],mod-2, mod);
        res%=mod;
        res*=modpow(fact[(nb1-cv)/2],mod-2, mod);
        res%=mod;
        
        //cout<<nb1<<" "<<cv<<" "<<n<<"===>";
        cout<<res<<"\n";

    }
}