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

const int MN = 4e5+5;
int N, M, S, i, x, y, vis[MN][2], cmp[MN], nxt, st[MN], sz[MN], sub[MN], ok[MN], lo, hi;
vi adj[MN], cadj[MN]; queue<int> q; stack<int> s;
set<pii> ans; pii ed[MN]; map<pii,pii> hm;

void dfs(int n,int p){
    vis[n][0]=vis[n][1]=++nxt;
    st[n]=1; s.push(n);
    for(auto v : adj[n]){
        if(v==p) continue;
        if(!vis[v][0]) dfs(v,n),vis[n][1]=min(vis[n][1],vis[v][1]);
        else if(st[v]) vis[n][1]=min(vis[n][1],vis[v][0]);
        if(!ans.count({v,n})) ans.insert({n,v});
    }
    if(vis[n][0]==vis[n][1]){
        S++;
        while(s.size()&&s.top()!=n){
            sz[S]++; cmp[s.top()]=S;
            st[s.top()]=0; s.pop();
        }
        sz[S]++; cmp[s.top()]=S;
        st[s.top()]=0; s.pop();
    }
}

int main(){
    for(scanf("%d%d",&N,&M),i=1;i<=M;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
        ed[i]={x,y};
    }
    for(i=1;i<=N;i++){
        if(!vis[i][0]) dfs(i,0);
    }
    for(i=1;i<=N;i++){
        for(auto v : adj[i]){
            if(cmp[v]!=cmp[i]){
                hm[{cmp[i],cmp[v]}]={i,v};
                cadj[cmp[i]].pb(cmp[v]);
                if(ans.count({i,v})) ans.erase({i,v});
                if(ans.count({v,i})) ans.erase({v,i});
            }
        }
    }
    lo=2, hi=N+1;
    while(lo<hi){
        int mid=(lo+hi)>>1;
        for(i=1;i<=S;i++){
            sub[i]=sz[i];
            if(sub[i]>=mid) q.push(i);
        }
        int cnt=0;
        while(q.size()){
            x=q.front(); q.pop(); cnt++;
            for(auto v : cadj[x]){
                sub[v]+=sub[x];
                if(sub[v]>=mid&&sub[v]-sub[x]<mid)
                    q.push(v);
            }
        }
        if(cnt==S) lo=mid+1;
        else hi=mid;
    }
    lo--;
    for(i=1;i<=S;i++){
        sub[i]=sz[i];
        if(sub[i]>=lo) q.push(i);
    }
    while(q.size()){
        x=q.front(); q.pop();
        for(auto v : cadj[x]){
            sub[v]+=sub[x];
            if(sub[v]>=lo&&sub[v]-sub[x]<lo){
                q.push(v);
                ans.insert(hm[{v,x}]);
            }
        }
    }
    printf("%d\n",lo);
    for(i=1;i<=M;i++){
        if(!ans.count(ed[i])) swap(ed[i].first,ed[i].second);
        printf("%d %d\n",ed[i].first,ed[i].second);
    }
    return 0;
}