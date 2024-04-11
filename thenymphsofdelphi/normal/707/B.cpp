#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int N = 100005;

vector <pair <int, int> > adj[N];

signed main(){
    int n, m, k, ans = 2e9;
    cin >> n >> m >> k;
    vector <int> a(k);
    if (k == 0 || k == n){
        cout << -1;
        return 0;
    }
    for (int i = 0; i < m; i++){
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].pb(mp(v, l));
        adj[v].pb(mp(u, l));
    }
    for (int i = 0; i < k; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < k; i++){
        for (int j = 0; j < adj[a[i]].size(); j++){
            if (!binary_search(a.begin(), a.end(), adj[a[i]][j].fi)){
                ans = min(ans, adj[a[i]][j].se);
            }
        }
    }
    if (ans == 2e9){
        cout << -1;
    }
    else{
        cout << ans;
    }
}