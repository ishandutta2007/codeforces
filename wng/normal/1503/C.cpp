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
    VL a(n);
    VL b(n);
    VL c(n);
    map<LL, int> ds;
    LL res=0;
    LL maxa=0LL;
    LL minb=1000000005LL;
    REP(i,n){
        RII(a[i],c[i]);
        b[i]=a[i]+c[i];
        ds[a[i]]++;
        ds[b[i]]--;
        res+=c[i];
        maxa=max(maxa, a[i]);
        minb=min(minb, b[i]);
    }
    //cout<<"preres "<<res<<" "<<maxa<<" "<<minb<<endl;
    LL previous=minb;
    int cs=0;
    LL economise=0;
    for (auto i: ds){
        if (cs){
            economise+=max(0LL, min(maxa,i.F)-previous);
        }
        cs+=i.S;
        previous=max(previous, i.F);
        if (previous>=maxa) break;
    }
    res+=max(0LL,maxa-minb-economise);
    cout<<res<<"\n";

}