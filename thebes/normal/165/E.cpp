#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

namespace debug{
    void __(short x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class P1,class P2>
    void __(const pair<P1,P2>&x){__("("),__(x.first),__(", "),__(x.second),__(")");}
    template<class T>
    void __(const vector<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    void screm(){__("\n");}
    template<class T1,class... T2>
    void screm(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" | "),screm(t2...);else __("\n");}
    void pr(){__("\n");}
    template<class T1,class... T2>
    void pr(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" "),pr(t2...);else __("\n");}
}

using namespace debug;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const int MN = 1e6+6, r = (1<<22)-1;
int dp[2][4*r], n, i, a[MN];

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[0][a[i]]=a[i];
    }
    for(i=1;i<=22;i++){
        for(int j=0;j<=r;j++){
            dp[i&1][j]=0;
            if(j&(1<<(i-1))) dp[i&1][j]=max(dp[i&1][j],dp[(i+1)&1][j^(1<<(i-1))]);
            dp[i&1][j]=max(dp[i&1][j],dp[(i+1)&1][j]);
        }
    }
    for(i=1;i<=n;i++){
        int c = (r^a[i]);
        int x = dp[0][c];
        printf("%d ",!x?-1:x);
    }
    printf("\n");
    return 0;
}