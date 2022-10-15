// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
// #define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int maxn=1000007;
const int mod=1e9+7;
int n,m;
vector<pii> g[maxn][2];
vector<tuple<int,int,int>> edges[2]; 
pii _from[maxn];
int actual_size[maxn][2];
int label[maxn];
bool vis[maxn];
bool vv[maxn];
vector<pii> h[maxn];
int aaa[maxn], deg[maxn];
    queue<int> ans;
    bool vvv[maxn];
void dfs(int u,int p){
    if (vv[u]) return;
    vv[u]=1;
    auto sgn=[&](int u){
        if (u>=0) return 1;
        else return -1;
    };
    auto bs=[&](int u){
        if (u<0) return ~u;
        return u;
    };
    for (auto [to,id]:h[u]){
        if (!vvv[bs(id)]) {
            label[bs(id)]=sgn(id);
            vvv[bs(id)]=1;
        // cerr<<u<<" "<<to<<" "<<bs(id)<<" "<<label[bs(id)]<<endl;
            ans.push(bs(id));
            dfs(to,u);
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    cin>>n>>m;
    while (sz(ans)) ans.pop();
    rep(i,m){
        int u,v,w;
        cin>>u>>v>>w;
        aaa[u]+=w, aaa[v]+=w;
        w--;
        edges[w].pb({u,v,i});
        g[u][w].pb({v,i}), g[v][w].pb({u,~i}), actual_size[u][w]++, actual_size[v][w]++;
    }
    int fk=0;
    for (int i=1;i<=n;++i) fk+=(aaa[i]&1);
                    auto sgn=[&](int u){
                    if (u>=0) return 1;
                    else return -1;
                };
                auto bs=[&](int u){
                    if (u<0) return ~u;
                    return u;
                };
                int cnt=m;
    rep(w,2){
        for (int i=1;i<=n;++i){
            while (actual_size[i][w]>1){
                auto get=[&](int u){
                    while (1){
                        auto ret=g[u][w].back();
                        g[u][w].pop_back();
                        if (vis[bs(ret.S)]) continue;
                        return ret;
                    }
                };
                auto ret1=get(i);
                auto ret2=get(i);
                if (ret1.F==ret2.F){
                    vis[bs(ret1.S)]=vis[bs(ret2.S)]=1;
                    // cerr<<"finish:"<<bs(ret1.S)<<" "<<bs(ret2.S)<<endl;
                    actual_size[ret1.F][w]-=2;
                    label[bs(ret1.S)]=sgn(ret1.S), label[bs(ret2.S)]=-sgn(ret2.S);
                    ans.push(bs(ret1.S)), ans.push(bs(ret2.S));
                }
                else{
                    vis[bs(ret1.S)]=vis[bs(ret2.S)]=1;
                    _from[cnt].F= ret1.S, _from[cnt].S=ret2.S;
                    int id=cnt;
                    edges[w].pb({ret1.F,ret2.F,id}), g[ret1.F][w].pb({ret2.F,id}), g[ret2.F][w].pb({ret1.F,~id});
                    // cerr<<"add: "<<ret1.F<<" "<<ret2.F<<" "<<id<<" "<<_from[cnt].F<<" "<<_from[cnt].S<<endl;
                    cnt++;
                }
                actual_size[i][w]-=2;
            }
        }
    }
    for (int w=0;w<2;++w){
        for (auto [u,v,id]:edges[w]){
            if (vis[id]) continue;
            h[u].pb({v,id}), h[v].pb({u,~id});
        }
    }
    for (int i=1;i<=n;++i){
        if (sz(h[i])>1) continue;
        if (vv[i]) continue;
        dfs(i,-1);
    }
    for (int i=1;i<=n;++i){
        // if (sz(h[i])>1) continue;
        if (vv[i]) continue;
        dfs(i,-1);
    }
    // for (int w=0;w<2;++w){
    //     for (auto [u,v,id]:edges[w]){
    //         if (vis[id]) continue;
    //         // cerr<<u<<" "<<v<<" "<<w<<" "<<id<<endl;
    //         if (label[id]>=0) deg[u]+=w+1, deg[v]-=w+1;
    //         else deg[u]-=w+1, deg[v]+=w+1;
    //     }
    // }
    // for (int i=1;i<=n;++i){
    //     cout<<deg[i]<<" ";
    //     assert(abs(deg[i])<3);
    // }
    // cout<<"\n";
    while (sz(ans)){
        int get=ans.front();
        ans.pop();
        if (!_from[get].F&&!_from[get].S) continue;
        auto [x,y]=_from[get];
        vis[get]=1;
        label[bs(x)]=-sgn(x)*label[get];
        label[bs(y)]=sgn(y)*label[get];
        ans.push(bs(x)), ans.push(bs(y));
        vis[bs(x)]=0, vis[bs(y)]=0;
        // memset(deg,0,sizeof(deg));
        // for (int w=0;w<2;++w){
        //     for (auto [u,v,id]:edges[w]){
        //         if (vis[id]) continue;
        //         if (label[id]>=0) deg[u]+=w+1, deg[v]-=w+1;
        //         else deg[u]-=w+1, deg[v]+=w+1;
        //     }
        // }
        // for (int i=1;i<=n;++i){
        //     cout<<deg[i]<<" ";
        // }
        // cout<<"\n";
    }
    // memset(deg,0,sizeof(deg));
    // for (int w=0;w<2;++w){
    //     for (auto [u,v,id]:edges[w]){
    //         if (id>=m) continue;
    //         if (label[id]>=0) deg[u]+=w+1, deg[v]-=w+1;
    //             else deg[u]-=w+1, deg[v]+=w+1;
    //         }
    //     }
    // for (int i=1;i<=n;++i){
    //     cout<<deg[i]<<" ";
    // }
    // cout<<"\n";
    cout<<fk<<"\n";
    for (int i=0;i<m;++i){
        if (label[i]>0) cout<<"2";
        else cout<<"1";
    }
    return 0; 
}

/*
1
5
7 7
5 6
-9 0
6 -1
-1 3
1
2
-4 9
-2 5
*/