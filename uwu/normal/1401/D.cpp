#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")
 
using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;
 
struct Edge{ int x,id; };
vector<Edge> graph[MAXN];
ll n,used[MAXN],sz[MAXN];
 
int dfs(int curr, int prev){
    sz[curr]=1;
    for (Edge x:graph[curr]){
        if (x.id==prev) continue;
        sz[curr]+=dfs(x.x,x.id);
    }
    used[prev]=(n-sz[curr])*sz[curr];
    return sz[curr];
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> n;
        for (int i=1;i<=n;++i) graph[i].clear(),used[i]=0,sz[i]=0;
        for (int i=1,a,b;i<=n-1;++i){
            cin >> a >> b;
            graph[a].push_back({b,i});
            graph[b].push_back({a,i});
        }
        dfs(1,0);
        priority_queue<ll> pq;
        int m; cin >> m;
        for (int i=1,p;i<=m;++i){
            cin >> p;
            pq.push(p);
        }
        for (int i=m+1;i<=n-1;++i) pq.push(1);
        sort(used+1,used+n); reverse(used+1,used+n);
        ll ans=0;
        for (int i=1;i<=n-1;++i){
            ll curr=1;
            while (pq.size()>=n-i) curr*=pq.top(), curr%=mod, pq.pop();
            //cout << used[i] << " : " << curr << '\n';
            ans+=curr*used[i], ans%=mod;
        }
        cout << ans << '\n';
    }
}