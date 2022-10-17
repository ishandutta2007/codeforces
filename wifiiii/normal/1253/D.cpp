#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int maxn = 200005;
vector<int> g[maxn];
int par[maxn], l[maxn], r[maxn];
int find(int x) {return x == par[x] ? x : par[x] = find(par[x]);}
void merge(int u, int v) {
    int x = find(u), y = find(v);
    if(x == y) return;
    par[x] = y;
    l[y] = min(l[x], l[y]);
    r[y] = max(r[x], r[y]);
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) par[i] = l[i] = r[i] = i;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        merge(u, v);
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {return l[i] < l[j];});
    int ans = 0, rr = -1;
    for(int i : ord) {
        if(i != find(i)) continue;
        if(l[i] <= rr) ++ans;
        rr = max(rr, r[i]);
    }
    cout << ans << endl;
}