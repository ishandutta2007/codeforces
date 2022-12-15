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

const int MN = 2e5+5;
int N, i, x, y, w, vs[MN], st[MN], ring[MN]; ll nxt[MN], ans[MN], sz[MN], dis[MN], len, idk[MN];
vector<pii> adj[MN]; stack<int> s;
vi cyc;

void detect(int n,int p){
    vs[n]=1; st[n]=1;
    s.push(n);
    for(auto v : adj[n]){
        if(v.first==p) continue;
        if(!vs[v.first]) detect(v.first,n);
        if(st[v.first]){
            while(s.size()&&s.top()!=v.first){
                cyc.pb(s.top()); s.pop();
            }
            cyc.pb(s.top()); s.pop();
        }
    }
    st[n]=0;
    if(s.size()&&s.top()==n) s.pop();
}

void dfs(int n,int p){
    sz[n]=1;
    for(auto v : adj[n]){
        if(v.first==p||ring[v.first]) continue;
        dfs(v.first, n);
        sz[n] += sz[v.first];
        ans[n] += 1LL*v.second*sz[v.first];
        ans[n] += ans[v.first];
    }
}

void dfs2(int n,int p,ll up){
    ll acc=0;
    for(auto v : adj[n]){
        if(v.first==p){
            up+=1LL*v.second*(N-sz[n]);
            ans[n]+=up;
            continue;
        }
        if(ring[v.first]) continue;
        acc+=ans[v.first]+1LL*v.second*sz[v.first];
    }
    for(auto v : adj[n]){
        if(v.first==p||ring[v.first]) continue;
        dfs2(v.first,n,up+acc-ans[v.first]-1LL*v.second*sz[v.first]);
    }
}

void prop(int n,int p,ll val){
    ans[n] += val;
    for(auto v : adj[n]){
        if(v.first==p||ring[v.first]) continue;
        prop(v.first, n, val);
    }
}

int main(){
    for(scanf("%d",&N),i=1;i<=N;i++){
        scanf("%d%d%d",&x,&y,&w);
        adj[x].pb({y,w});
        adj[y].pb({x,w});
    }
    detect(1,0);
    for(auto v : cyc)
        ring[v]=1;
    len = 0;
    for(i=1;i<(int)cyc.size();i++){
        for(auto v : adj[cyc[i]]){
            if(v.first==cyc[i-1]){
                dis[cyc[i]]=dis[v.first]+v.second;
                idk[cyc[i]]=v.second;
                nxt[cyc[i-1]]=v.second;
                len += v.second;
                break;
            }
        }
    }
    for(auto v : adj[cyc[0]]){
        if(v.first==cyc.back()){
            len+=v.second;
            nxt[cyc.back()]=v.second;
            idk[cyc[0]]=v.second;
            break;
        }
    }
    ll sigma = 0;
    for(auto v : cyc){
        dfs(v,0);
        dfs2(v,0,0);
        sigma += ans[v];
    }
    for(auto v : cyc){
        prop(v,0,sigma-ans[v]);
    }
    ll ls=sz[cyc[0]], rs=0, lsm=0, rsm=0, j, dist=idk[cyc[0]];
    for(i=(int)cyc.size()-1;i>0;i--){
        rs+=sz[cyc[i]];
        rsm+=dist*sz[cyc[i]];
        dist+=idk[cyc[i]];
    }
    dist=0;
    for(i=j=0;i<(int)cyc.size();i++){
        while((dist+nxt[cyc[j]])*2<=len){
            dist+=nxt[cyc[j]];
            j=(j+1)%cyc.size();
            ll dis2=len-dist;
            rs-=sz[cyc[j]];
            rsm-=1LL*dis2*sz[cyc[j]];
            ls+=sz[cyc[j]];
            lsm+=1LL*dist*sz[cyc[j]];
        }
        ls-=sz[cyc[i]]; rs+=sz[cyc[i]];
        ll cur = lsm+rsm;
        prop(cyc[i],0,cur);
        if(i+1!=cyc.size()){
            ll nxt=dis[cyc[i+1]]-dis[cyc[i]];
            lsm-=ls*nxt; rsm+=rs*nxt;
            dist-=nxt;
        }
    }
    for(i=1;i<=N;i++)
        printf("%lld ",ans[i]);
    pr();
    return 0;
}