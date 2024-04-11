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
vector<int> es[MAX_V], rs[MAX_V];
vector<bool> used(MAX_V, false);

void add_edge(int from, int to){
    es[from].pb(to), rs[to].pb(from);
}

ll ans = 0;
ll A[MAX_V];

ll dfs1(int now){
    for(auto &e: es[now]){
        ll memo = dfs1(e);
        if(memo >= 0) A[now] += memo;
    }
    ans += A[now];
    return A[now];
}

vector<ll> ord;

void dfs2(int now){
    for(auto &e: es[now]){
        if(A[e] < 0) dfs2(e);
    }
    ord.pb(now);
    for(auto &e: es[now]){
        if(A[e] >= 0) dfs2(e);
    }
}

int main(){
    int N;
    cin >> N;
    rep(i, N) cin >> A[i];
    rep(i, N){
        int u; cin >> u; u--;
        if(u >= 0) add_edge(u, i);
    }
    rep(i, N) if(rs[i].empty()) dfs1(i);
    rep(i, N) if(rs[i].empty()) dfs2(i);
    cout << ans << endl;
    reverse(all(ord));
    for(auto &e: ord) cout << e+1 << ' '; cout << endl;
}