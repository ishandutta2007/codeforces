#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

const int maxn = 200005;
int a[maxn];
vector<int> g[maxn];
queue<int> q[3];
int calc(int cur, int n, vector<int> deg) {
    int cnt = 0, ret = 0;
    vector<int> vis(n+1);
    for(int i=1;i<=2;++i) while(!q[i].empty()) q[i].pop();
    for(int i=1;i<=n;++i) if(deg[i] == 1) {
        if(!a[i]) q[cur].push(i);
        else q[a[i]].push(i);
        vis[i]=1;
    }
    while(cnt != n) {
        ++ret;
        while(!q[cur].empty()) {
            int u = q[cur].front(); q[cur].pop();
            cnt++;
            for(int v : g[u]) {
                if(vis[v]) continue;
                if(--deg[v] == 1) {
                    vis[v] = 1;
                    if(!a[v]) q[cur].push(v);
                    else q[a[v]].push(v);
                }
            }
        }
        cur = 3 - cur;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ii cin >> a[i];
        if(n == 1) {
            cout << 1 << endl;
            continue;
        }
        ii g[i].clear();
        vector<int> deg(n+1);
        for(int i=1;i<n;++i) {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        cout << min(calc(1, n, deg), calc(2, n, deg)) << endl;
    }
}