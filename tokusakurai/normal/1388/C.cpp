#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

const int MAX_V = 200000;

int p[MAX_V], h[MAX_V], sum[MAX_V];
vector<int> es[MAX_V];

int dfs1(int now, int pre){
    sum[now] = p[now];
    for(auto &e: es[now]){
        if(e == pre) continue;
        sum[now] += dfs1(e, now);
    }
    return sum[now];
}

bool ans;

pii dfs2(int now, int pre){
    int p = sum[now]+h[now], q = sum[now]-h[now];
    if(p < 0 || q < 0 || p&1){
        ans = false;
        return pii(0, 0);
    }
    int s = 0;
    for(auto &e: es[now]){
        if(e == pre) continue;
        int a, b;
        tie(a, b) = dfs2(e, now);
        s += a;
    }
    if(s > p/2) ans = false;
    return pii(p/2, q/2);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;
        rep(i, N) cin >> p[i];
        rep(i, N) cin >> h[i];
        rep(i, N-1){
            int u, v; cin >> u >> v; u--, v--;
            es[u].pb(v), es[v].pb(u);
        }
        dfs1(0, -1);
        ans = true;
        dfs2(0, -1);
        cout << (ans? "YES" : "NO") << endl;
        rep(i, N) es[i].clear();
    }
}