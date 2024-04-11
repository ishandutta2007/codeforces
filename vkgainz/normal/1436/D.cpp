#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
vector<int> adj[200001];
ll a[200001];
ll sum[200001];
ll sz[200001];
bool work = true;
void dfs1(int curr, int par) {
    bool leaf = false;
    if(par!=-1) leaf = adj[curr].size()==1;
    for(int next : adj[curr]) if(next!=par) {
        dfs1(next,curr);
        sz[curr]+=sz[next];
        sum[curr]+=sum[next];
    }
    sum[curr]+=a[curr];
    if(leaf) {
        sum[curr] = a[curr];
        sz[curr] = 1;
    }
}
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n-1;i++) {
        int p; cin >> p;
        --p;
        adj[i+1].push_back(p);
        adj[p].push_back(i+1);
    }
    ll mx = 0;
    for(int i=0;i<n;i++) cin >> a[i], mx = max(mx,a[i]);
    dfs1(0,-1);
    ll ans = 0;
    for(int i=0;i<n;i++) ans = max(ans,(sum[i]+sz[i]-1)/sz[i]);
    cout << ans << endl;
}