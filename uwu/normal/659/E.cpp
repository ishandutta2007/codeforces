#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

set<int> adj[MAXN];
int ans=0;
bool inq[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    queue<int> q;
    for (int i=1;i<=n;++i){
        if (adj[i].size()==0) ans++;
        else if (adj[i].size()==1) q.push(i), inq[i]=1;
    }
    while (!q.empty()){
        int v=q.front(); q.pop();
        if (adj[v].size()==0) ans++;
        else{
            for (int x:adj[v]){
                adj[x].erase(v);
                if (adj[x].size()==1&&!inq[x]) inq[x]=1, q.push(x);
            }
            adj[v].clear();
        }
    }
    cout << ans << '\n';
}