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

const int MN = 1e4+5, MM = 1005;
int n, m, i, j, arr[MN], g, r, d; ll ans, dp[MN][MM];
bitset<MM> vs[MN], st[MN];
queue<pii> q;

int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=m;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr+1,arr+m+1);
    scanf("%d%d",&g,&r);
    memset(dp,0x3f,sizeof(dp));
    q.push({1,0});
    dp[1][0]=0; st[1][0]=1;
    while(q.size()){
        pii cur=q.front(); q.pop();
        st[cur.first][cur.second]=0;
        vs[cur.first][cur.second]=1;
        if(cur.first<m){
            d=arr[cur.first+1]-arr[cur.first];
            if(cur.second+d<=g&&dp[cur.first][cur.second]+d<dp[cur.first+1][(cur.second+d)%g]){
                dp[cur.first+1][(cur.second+d)%g]=dp[cur.first][cur.second]+d;
                if(!st[cur.first+1][(cur.second+d)%g]){
                    q.push({cur.first+1,(cur.second+d)%g});
                    st[cur.first+1][(cur.second+d)%g]=1;
                }
            }
        }
        if(cur.first>1){
            d=arr[cur.first]-arr[cur.first-1];
            if(cur.second+d<=g&&dp[cur.first][cur.second]+d<dp[cur.first-1][(cur.second+d)%g]){
                dp[cur.first-1][(cur.second+d)%g]=dp[cur.first][cur.second]+d;
                if(!st[cur.first-1][(cur.second+d)%g]){
                    q.push({cur.first-1,(cur.second+d)%g});
                    st[cur.first-1][(cur.second+d)%g]=1;
                }
            }
        }
    }
    int ok=0;
    ans=1LL<<60;
    for(j=0;j<g;j++){
        if(vs[m][j]){
            ll heh=dp[m][j]-1;
            ans=min(ans,dp[m][j]+(heh/g)*r);
            ok=1;
        }
    }
    if(!ok) printf("-1\n");
    else printf("%lld\n",ans);
    return 0;
}