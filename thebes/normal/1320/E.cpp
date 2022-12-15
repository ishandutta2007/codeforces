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
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 2e5+5, LG = 20;
int n, q, m, k, sz, i, j, x, y, vis[MN][2], nxt, sp[MN], ans[MN], anc[MN][LG], dep[MN], loc[MN];
double ini[MN]; int tp[MN], qid[MN];
vi arr, adj[MN], t[MN]; stack<int> st;
struct tup{double t; int ch, id;}a[MN], b[MN];

void dfs(int n,int p,int d){
    anc[n][0] = p;
    vis[n][0] = ++nxt;
    dep[n] = d;
    for(auto v : adj[n]){
        if(v==p) continue;
        dfs(v, n, d+1);
    }
    vis[n][1] = ++nxt;
}

inline int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=LG-1;i>=0;i--){
        if(dep[x]-dep[y]>=(1<<i)){
            x = anc[x][i];
        }
    }
    if(x==y) return x;
    for(int i=LG-1;i>=0;i--){
        if(anc[x][i]!=anc[y][i]){
            x = anc[x][i];
            y = anc[y][i];
        }
    }
    return anc[x][0];
}

inline int dis(int x,int y){
    int res=0;
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=LG-1;i>=0;i--){
        if(dep[x]-dep[y]>=(1<<i)){
            x = anc[x][i];
            res += (1<<i);
        }
    }
    if(x==y) return res;
    for(int i=LG-1;i>=0;i--){
        if(anc[x][i]!=anc[y][i]){
            x = anc[x][i];
            y = anc[y][i];
            res += (1<<(i+1));
        }
    }
    return res+2;
}

void solve(int n,int p){
    a[n].t=b[n].t=1e12;
    a[n].id=b[n].id=0;
    for(auto v : t[n]){
        if(v==p) continue;
        solve(v, n);
        int id = a[v].id;
        if(id){
            double nt = ceil(dis(loc[id],n)/(double)sp[id])+ini[loc[id]];
            if(nt<a[n].t){
                b[n] = a[n];
                a[n].t = nt;
                a[n].id = id;
                a[n].ch = v;
            }
            else if(nt<b[n].t){
                b[n].t = nt;
                b[n].id = id;
                b[n].ch = v;
            }
        }
    }
    if(tp[n]){
        b[n] = a[n];
        a[n].t = ini[n];
        a[n].id = tp[n];
        a[n].ch = -1;
    }
}

void solve2(int n,int p,int id){
    double tm = 1e13;
    if(id) tm = ceil(dis(loc[id],n)/(double)sp[id])+ini[loc[id]];
    if(qid[n]){
        if(id&&tm<a[n].t) ans[qid[n]]=id;
        else ans[qid[n]]=a[n].id;
    }
    for(auto v : t[n]){
        if(v==p) continue;
        if(v==a[n].ch){
            if(tm<b[n].t) solve2(v,n,id);
            else solve2(v,n,b[n].id);
        }
        else{
            if(tm<a[n].t) solve2(v,n,id);
            else solve2(v,n,a[n].id);
        }
    }
}

int main(){
    for(scanf("%d",&n),i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 0, 1);
    for(j=1;j<LG;j++){
        for(i=1;i<=n;i++){
            anc[i][j]=anc[anc[i][j-1]][j-1];
        }
    }
    for(scanf("%d",&q);q;q--){
        scanf("%d%d",&k,&m);
        arr.clear();
        for(i=1;i<=k;i++){
            scanf("%d%d",&x,&y);
            ini[x]=(i-1)/(double)k;
            tp[x]=i; sp[i]=y;
            arr.pb(x);
            loc[i] = x;
        }
        for(i=1;i<=m;i++){
            scanf("%d",&x);
            qid[x] = i;
            arr.pb(x);
        }
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        sort(arr.begin(),arr.end(),[](int i,int j){return vis[i][0]<vis[j][0];});
        int tmp = arr.size();
        for(i=0;i<tmp-1;i++){
            arr.pb(lca(arr[i],arr[i+1]));
        }
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        sort(arr.begin(),arr.end(),[](int i,int j){return vis[i][0]<vis[j][0];});
        for(auto v : arr) t[v].clear();
        while(st.size()) st.pop();
        for(auto v : arr){
            while(st.size()){
                int id = st.top();
                if(vis[id][0]<=vis[v][0]&&vis[id][1]>=vis[v][1]) break;
                else st.pop();
            }
            if(st.size()){
                t[st.top()].pb(v);
                t[v].pb(st.top());
            }
            st.push(v);
        }
        solve(arr[0],0);
        solve2(arr[0],0,0);
        for(i=1;i<=m;i++) printf("%d ",ans[i]);
        printf("\n");
        for(auto v : arr){
            tp[v] = ini[v] = qid[v] = 0;
        }
    }
    return 0;
}