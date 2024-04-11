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
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct Graph{
    vector<vector<int>> es;
    vector<int> col;
    const int n;

    Graph(int n) : n(n){
        es.resize(n), col.resize(n);
    }

    void add_edge(int from, int to, bool directed = false){
        es[from].pb(to);
        if(!directed) es[to].pb(from);
    }

    int dfs(int now, int pre){
        col[now] = 0;
        for(auto &e: es[now]){
            if(e == pre) continue;
            col[now] = dfs(e, now)^1;
        }
        return col[now];
    }
};

int main(){
    int N;
    cin >> N;
    int a[N];
    rep(i, N) cin >> a[i];
    Graph G(N);
    rep2(i, 1, N-1){
        int p; cin >> p; p--;
        G.add_edge(p, i);
    }
    G.dfs(0, -1);
    map<int, ll> mp1, mp2;
    int sum = 0;
    ll n = 0, m = 0;
    rep(i, N){
        if(G.col[i] == 0) sum ^= a[i], n++, mp1[a[i]]++;
        else m++, mp2[a[i]]++;
    }
    ll ans = 0;
    if(sum == 0) ans += n*(n-1)/2 + m*(m-1)/2;
    for(auto &e: mp1){
        int tmp = sum^e.first;
        if(mp2.count(tmp)) ans += e.second*mp2[tmp];
    }
    cout << ans << endl;
}