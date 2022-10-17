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
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<ll,int> pii;

const int maxn = 100005;
struct edge {
    int u, v, w;
    bool operator < (const edge & e) const {
        return w < e.w;
    }
}es[maxn];
int vis[maxn], vis2[maxn];

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;++i) {
        int u, v, w;
        cin >> u >> v >> w;
        es[i] = {u, v, w};
    }
    sort(es+1,es+1+m);
    int lo = 1, hi = 1e9+1, f = 0;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        memset(vis, 0, sizeof(vis));
        memset(vis2, 0, sizeof(vis));
        int ok = 1, tot = 2 * n;
        for(int i=1;i<=m;++i) {
            int u = es[i].u, v = es[i].v;
            if(es[i].w > mid) break;
            if(!vis[u]) vis[u] = 1, tot--;
            if(!vis2[v]) vis2[v] = 1, tot--;
            if(tot == 0) break;
        }
        if(tot == 0) f = 1, hi = mid;
        else lo = mid + 1;
    }
    if(!f) cout << -1 << endl;
    else cout << lo << endl;
}