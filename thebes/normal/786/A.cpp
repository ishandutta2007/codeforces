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
#define fox(i,x,y) for(int i=(x);i<=(y);i++)

const int MN = 7005;
int N, dp[MN][2], i, j, x, k, d[MN][2], in[MN][2];
vi a[2];
struct re{short x, y, w;};
queue<re> q;

void rec(int aaaa,int aa,int aaa){
    re c = {aaaa, aa, aaa};
    c.y = !c.y; c.w = !c.w;
    dp[c.x][c.y]=max(dp[c.x][c.y],(int)c.w);
    in[c.x][c.y]++;
    if(d[c.x][c.y]) return;
    if(dp[c.x][c.y]||in[c.x][c.y]>=a[c.y].size()||c.x==N){
        d[c.x][c.y] = 1;
        for(auto v : a[!c.y]){
            int nx = c.x-v;
            if(nx<=0) nx += N;
            if(!d[nx][!c.y]) rec(nx,c.y,dp[c.x][c.y]);
        }
    }
}

int main(){
    scanf("%d",&N);
    for(scanf("%d",&k);k;k--){
        scanf("%d",&x);
        a[0].pb(x);
    }
    for(scanf("%d",&k);k;k--){
        scanf("%d",&x);
        a[1].pb(x);
    }
    memset(dp,-1,sizeof(dp));
    dp[N][0]=dp[N][1]=0; d[N][0]=d[N][1]=1;
    for(auto v : a[0]) rec(N-v,1,0);
    for(auto v : a[1]) rec(N-v,0,0);
    for(i=1;i<N;i++){
        if(dp[i][0]==1) printf("Win ");
        else if(d[i][0]) printf("Lose ");
        else printf("Loop ");
    }
    printf("\n");
    for(i=1;i<N;i++){
        if(dp[i][1]==1) printf("Win ");
        else if(d[i][1]) printf("Lose ");
        else printf("Loop ");
    }
    printf("\n");
    return 0;
}