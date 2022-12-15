#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void __(short x){cout<<x;}
    void __(unsigned x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void __(const pair<S,T>&x){__(DEBUG?"(":""),__(x.first),__(DEBUG?", ":" "),__(x.second),__(DEBUG?")":"");}
    template<class T>
    void __(const vector<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const set<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const multiset<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class S,class T>
    void __(const map<S,T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    void pr(){cout<<"\n";}
    template<class S,class... T>
    void pr(const S&a,const T&...b){__(a);if(sizeof...(b))__(' ');pr(b...);}
}

using namespace output;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)
#define F first
#define S second

const int MN = 1e5+5, MM = 5000;
int k, n, m, b, t, i, j, x, y, arr[MN], nxt;
map<int,int> mp; vector<pii> dp[MN]; vi pre[MN];

int main(){
    scanf("%d%d%d%d",&k,&n,&b,&t);
    m = min(n, b);
    while(k--){
        mp.clear(); nxt = 0;
        for(i=1;i<=n;i++){
            scanf("%d",&arr[i]);
            mp[arr[i]]=0;
        }
        i=0;
        for(auto it=mp.begin();it!=mp.end();it++)
            it->second = ++i;
        for(i=1;i<=n;i++)
            arr[i]=mp[arr[i]];
        m = mp.size();
        for(i=1;i<=m;i++){
            pre[i].clear();
            pre[i].resize(n+1);
            int prev = -1;
            for(j=1;j<=n;j++){
                if(arr[j]==i) prev=j;
                pre[i][j]=prev;
            }
            for(j=1;j<=n;j++){
                if(pre[i][j]==-1)
                    pre[i][j]=prev;
            }
        }
        for(i=1;i<=m;i++){
            dp[i].clear();
            dp[i].resize(m+1);
        }
        dp[m][0]={n,t};
        dp[m][1]={pre[m][n],t};
        int ans = 0;
        for(i=m;i>=1;i--){
            for(j=0;j<=m;j++){
                if(dp[i][j].F||dp[i][j].S){
                    ans=max(ans,j);
                    if(i>1){ // propagate
                        // take i-1
                        int nx = pre[i-1][dp[i][j].F], ny = dp[i][j].S;
                        if(nx>dp[i][j].F) ny--;
                        if(ny>=1){
                            if(ny>dp[i-1][j+1].S) dp[i-1][j+1]={nx,ny};
                            else if(ny==dp[i-1][j+1].S&&nx>dp[i-1][j+1].F) dp[i-1][j+1]={nx,ny};
                        }
                        // meh, do anything
                        nx = dp[i][j].F, ny = dp[i][j].S;
                        if(ny>dp[i-1][j].S) dp[i-1][j]={nx,ny};
                        else if(ny==dp[i-1][j].S&&nx>dp[i-1][j].F) dp[i-1][j]={nx,ny};
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}