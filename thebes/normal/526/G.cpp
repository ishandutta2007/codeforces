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

const int MN = 1e5+5, LG = 20;
int N, Q, i, j, x, y, w, sp[LG][MN], dep[MN], rt, par[MN], vs[MN], ans[MN], sna[MN], t[MN], vis[MN][2], dis[MN], nxt; ll lst;
struct pq{bool operator()(const pii&i,const pii&j){return i.S>j.S;}};
priority_queue<pii,vector<pii>,pq> q;
vector<pii> adj[MN], go;
pii a[MN], b[MN], pref[MN];

void dfs(int n,int p,int d){
    dep[n] = d; par[n] = p;
    sp[0][n] = p; vis[n][0] = ++nxt;
    for(auto v : adj[n]){
        if(v.F==p) continue;
        dis[v.F] = dis[n]+v.S;
        dfs(v.F, n, d+1);
        pii tmp={a[v.F].F+v.S, v.F};
        if(tmp.F>a[n].F) b[n]=a[n], a[n]=tmp;
        else if(tmp.F>b[n].F) b[n]=tmp;
    }
    vis[n][1] = nxt;
}

void dfs2(int n,int up){
    ans[n] = a[n].F+max(up,b[n].F);
    vector<pii> sub;
    for(auto v : adj[n]){
        if(v.F==par[n]) continue;
        if(v.F==a[n].S) dfs2(v.F,max(up,b[n].F)+v.S);
        else dfs2(v.F,max(up,a[n].F)+v.S);
        sub.pb({pref[v.F].F+v.S,pref[v.F].S});
    }
    sort(sub.begin(),sub.end(),[](pii i,pii j){return i.F>j.F;});
    if(sub.size()){
        for(int i=1;i<(int)sub.size();i++)
            go.pb(sub[i]);
        pref[n]=sub[0];
    }
    else pref[n]={0, n};
}

inline void mrk(int x,int cur){
    while(!t[x]){
        t[x] = cur;
        x = par[x];
    }
}

inline bool con(int x,int y){
    return vis[x][0]<=vis[y][0]&&vis[x][1]>=vis[y][1];
}

int main(){
    scanf("%d%d",&N,&Q);
    for(i=1;i<N;i++){
        scanf("%d%d%d",&x,&y,&w);
        adj[x].pb({y,w});
        adj[y].pb({x,w});
    }
    q.push({1,0});
    while(q.size()){
        pii cur=q.top(); q.pop();
        if(vs[cur.F]) continue;
        vs[cur.F] = 1; rt = cur.F;
        for(auto v : adj[cur.F]){
            if(vs[v.F]) continue;
            q.push({v.F,v.S+cur.S});
        }
    }
    dfs(rt, 0, 0);
    dfs2(rt, 0);
    for(j=1;j<LG;j++){
        for(i=1;i<=N;i++)
            sp[j][i]=sp[j-1][sp[j-1][i]];
    }
    go.pb(pref[rt]);
    int cur=0;
    sort(go.begin(),go.end(),[](pii i,pii j){return i.F>j.F;});
    int sub;
    for(auto v : adj[rt]){
        if(con(v.F,go[0].S)){
            sub = v.F;
            break;
        }
    }
    bool ok = 0;
    for(i=1;i<(int)go.size();i++){
        if(!con(sub,go[i].S)){
            pii cur=go[i]; ok = 1;
            go.erase(go.begin()+i);
            go.insert(go.begin()+1,cur);
            break;
        }
    }
    if(!ok) go.insert(go.begin()+1,make_pair(0,0));
    for(i=1;i<=N;i++){
        sna[i]=sna[i-1];
        for(j=0;j<2;j++){
            if(cur<go.size()){
                sna[i]+=go[cur].F;
                mrk(go[cur++].S,i);
            }
        }
    }
    for(;Q;Q--){
        scanf("%d%d",&x,&y);
        x=(x+lst-1)%N+1;
        y=(y+lst-1)%N+1;
        if(y==1) lst = ans[x];
        else{
            if(t[x]<=y) lst = sna[y];
            else{
                int c = x;
                for(i=LG-1;i>=0;i--){
                    if(t[sp[i][c]]>y)
                        c=sp[i][c];
                }
                c=sp[0][c];
                lst = sna[y]-min(go[2*y-1].F,min(pref[c].F,dis[c]))+a[x].F+dis[x]-dis[c];
            }
        }
        printf("%lld\n",lst);
    }
    return 0;
}