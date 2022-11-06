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
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<N; ___I++) scanf("%d", &(X[___I]))  
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

const int mod = 1000000007;
const int m=60;
int main(){
    CASET{
        DRI(n);
        VL x(n);
        REP(i,n) {scanf("%I64d", &(x[i]));}
        LL c=0;
        VL mods(m+1,1);
        REPP(i,1,m+1){
            mods[i]=(mods[i-1]*2)%mod;
        }
        //cout<<"mods :"<<endl;
        //for (auto i:mods) cout<<i<<" "; cout<<endl;
        VL a(m,0);
        REP(i,n) {
            c+=(x[i]%mod);
            c%=mod;
            LL t=1;
            REP(k,m){
                if (t&x[i]) a[k]++;
                t<<=1;
            }
        }
        //cout<<"a :"<<endl;
        //for (auto i:a) cout<<i<<" "; cout<<endl;
        VL g(n,0);
        REP(i,n){
            LL t=1;
            LL r=0;
            REP(k,m){
                if (t&x[i]) {
                    r+=a[k]*mods[k];
          //              cout<<"adding "<<i<<" "<<k<<" "<<x[i]<<" "<<r<<endl;
                    }
                t<<=1;
                r%=mod;
            }
            g[i]=(r+mod)%mod;
        }
        //cout<<"gj :"<<endl;
        //for (auto i:g) cout<<i<<" "; cout<<endl;
        LL r=0;
        REP(i,n){
            LL ta=0;
            ta+=((((x[i]%mod)*g[i])%mod)*n)%mod;
            ta+=(g[i]*c)%mod;
            ta-=(g[i]*g[i])%mod;
            ta%=mod;
            r+=ta;
        }
        r%=mod;
        r+=mod;
        r%=mod;
        //cout<<"REEEES       ======================>";
        printf("%I64d\n", r);
    }
}