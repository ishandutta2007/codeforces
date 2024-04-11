#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

bool ans;
vector<int> graph[MAXN];
ll h[MAXN],p[MAXN],idx[MAXN];

ll dfs1(int curr, int prev){
    for (int x:graph[curr]){
        if (x==prev) continue;
        p[curr]+=dfs1(x,curr);
    }
    return p[curr];
}

ll dfs2(int curr, int prev){
    ll tot=0;
    for (int x:graph[curr]){
        if (x==prev) continue;
        tot+=dfs2(x,curr);
    }
    if (tot>h[curr]) ans=0;
    return h[curr];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n,m; cin >> n >> m;
        ans=1;
        for (int i=1;i<=n;++i) graph[i].clear(), cin >> p[i];
        for (int i=1;i<=n;++i) cin >> idx[i];
        for (int i=1,a,b;i<n;++i){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs1(1,1);
        for (int i=1;i<=n;++i){
            if (abs(idx[i])>p[i]) ans=0;
            if (abs(idx[i]-p[i])%2==1) ans=0;
            h[i]=(idx[i]+p[i])/2;
        }
        dfs2(1,1);
        if (ans) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}