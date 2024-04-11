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

const int MN = 3e5+5, MS = 550;
int n, m, i, x, y, ans, dis[MN], par[MN], tp, a, b, c, vs[MN], pre[MN], cnt;
set<int> adj[MN], st; vi sna, sq; queue<int> q;

int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        adj[x].insert(y);
        adj[y].insert(x);
    }
    memset(dis,-1,sizeof(dis));
    memset(par,-1,sizeof(par));
    q.push(1); dis[1]=0;
    while(q.size()){
        x=q.front(); q.pop();
        for(auto v : adj[x]){
            if(dis[v]!=-1) continue;
            dis[v]=dis[x]+1;
            par[v]=x;
            q.push(v);
        }
    }
    if(dis[n]!=-1) ans=dis[n],tp=1;
    else ans=1<<30;
    set<int> S, T;
    for(i=2;i<=n;i++){
        if(adj[1].count(i)) S.insert(i);
        else T.insert(i);
    }
    bool dn=0;
    for(auto u : S){
        for(auto v : adj[u]){
            if(T.count(v)){
                dn=1;
                if(ans>4){
                    ans=4; tp=2;
                    a=1, b=u, c=v;
                }
                break;
            }
        }
        if(dn) break;
    }
    for(auto u : S)
        adj[u].erase(1);
    for(auto u : S){
        if(vs[u]||dn) continue;
        st.clear();
        q.push(u); vs[u]=1;
        while(q.size()){
            x = q.front(); q.pop();
            for(auto v : st){
                if(!adj[x].count(v)){
                    dn=1;
                    if(ans>5){
                        ans=5; tp=3;
                        a=x, b=pre[x], c=v;
                    }
                    break;
                }
            }
            for(auto v : adj[x]){
                if(!vs[v]){
                    vs[v]=1;
                    pre[v]=x;
                    q.push(v);
                }
            }
            st.insert(x);
            if(dn) break;
        }
    }
    if(ans==1<<30) printf("-1\n");
    else if(tp==1){
        x=n;
        while(x>0){
            sna.pb(x);
            x=par[x];
        }
        reverse(sna.begin(),sna.end());
        printf("%d\n",ans);
        for(auto v : sna)
            printf("%d ",v);
        pr();
    }
    else if(tp==2) printf("%d\n%d %d %d %d %d\n",ans,a,b,c,a,n);
    else printf("%d\n%d %d %d %d %d %d\n",ans,1,a,b,c,a,n);
    return 0;
}