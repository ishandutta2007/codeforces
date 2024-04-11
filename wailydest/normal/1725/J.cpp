//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,sse")
#include <bits/stdc++.h>
#define y1 y_1
//#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
//#define prev aboba
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<vector<char> >frame;
const int N=600010;
const ll mod=998244353;
const ll inf=1e18;
vector<pair<int,ll> >g[N];
ll sumE[N];
ll d[N];
ll sub[N];
ll super[N];
void dfs0(int v,int pr){
    sumE[v]=0;
    d[v]=0;
    sub[v]=0;
    for (auto [to,w]:g[v]){
        if (to==pr) continue;
        dfs0(to,v);
        sumE[v]+=sumE[to]+w;
        sub[v]=max(sub[v],d[v]+d[to]+w);
        sub[v]=max(sub[v],sub[to]);
        d[v]=max(d[v],d[to]+w);
    }
}
vector<ll>best[N];
ll ans=0ll;
void dfs(int v,int pr){
    ans=min(ans,sumE[1]*2ll-best[v][0]-best[v][1]-best[v][2]-best[v][3]);
    for (auto [to,w]:g[v]){
        if (to==pr) continue;
        super[to]=max(best[v][0]+best[v][1]+best[v][2]-max(best[v][2],d[to]+w),super[v]);
        ans=min(ans,sumE[1]*2ll-w*2ll-super[to]-sub[to]);
        ll dv=d[v];
        if (dv==d[to]+w) dv=best[v][1];
        swap(d[v],dv);
        ll dto=max(d[to],d[v]+w);
        swap(d[to],dto);
        best[to].clear();
        for (auto [to1,w1]:g[to]){
            best[to].push_back(d[to1]+w1);
        }
        while (best[to].size()<4) best[to].push_back(0);
        sort(best[to].begin(),best[to].end());
        reverse(best[to].begin(),best[to].end());
        while (best[to].size()>4) best[to].pop_back();
        dfs(to,v);
        swap(d[to],dto);
        swap(d[v],dv);
    }
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        ll c;cin>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    dfs0(1,0);
    for (auto [to,w]:g[1]){
        best[1].push_back(d[to]+w);
    }
    while (best[1].size()<4) best[1].push_back(0);
    sort(best[1].begin(),best[1].end());
    reverse(best[1].begin(),best[1].end());
    while (best[1].size()>4) best[1].pop_back();
    ans=sumE[1]*2ll-sub[1];
    dfs(1,0);
    cout<<ans<<'\n';


}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;

    while (tt--){
        solve();
    }
    return 0;

}
///WRONG CYCLE
//124x
//xx3_
//xxxx



/*
5
1 2 1
2 3 1
3 4 1
4 5 4
*/