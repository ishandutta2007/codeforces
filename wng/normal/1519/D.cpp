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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    DRI(n);
    LL sb=0;
    DRVL(n,a);
    DRVL(n,b);
    REP(i,n) sb+=a[i]*b[i];
    //cout<<sb<<endl;
    LL mstb=0;    
    REP(i,n){
        LL stb=0;
        REPP(j, 1,min(i+1,n-i)){
            //cout<<(i-j)<<" "<<(i+j)<<endl;
            stb+=(a[i+j]*b[i-j] + a[i-j]*b[i+j] - a[i+j]*b[i+j]-a[i-j]*b[i-j]);
            mstb=max(mstb, stb);
        }
    }
    REP(i,n-1){
        LL stb=0;
        REP(j, min(n-i-1, i+1)){
            stb+=(a[i+1+j]*b[i-j] + a[i-j]*b[i+1+j] - a[i+1+j]*b[i+1+j]-a[i-j]*b[i-j]);
            mstb=max(mstb, stb);
        }
    }
    cout<<(sb+mstb)<<"\n";
}