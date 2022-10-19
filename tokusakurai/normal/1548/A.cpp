#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

int main(){
    int N, M; cin >> N >> M;

    vector<set<int>> s(N);
    rep(i, N) s[i].emplace(-1);

    rep(i, M){
        int u, v; cin >> u >> v; u--, v--;
        s[u].emplace(v), s[v].emplace(u);
    }

    int ans = 0;
    vector<int> c(N, 0);
    rep(i, N){
        if(*s[i].rbegin() < i) c[i] = 1;
        ans += c[i];
    }

    int Q; cin >> Q;

    while(Q--){
        int t; cin >> t;

        if(t == 1){
            int u, v; cin >> u >> v; u--, v--;
            s[u].emplace(v), s[v].emplace(u);
            if(c[u] == 1 && u < v) c[u] = 0, ans--;
            if(c[v] == 1 && v < u) c[v] = 0, ans--;
        }
        if(t == 2){
            int u, v; cin >> u >> v; u--, v--;
            s[u].erase(v), s[v].erase(u);
            if(c[u] == 0 && *s[u].rbegin() < u) c[u] = 1, ans++;
            if(c[v] == 0 && *s[v].rbegin() < v) c[v] = 1, ans++;
        }
        if(t == 3){
            cout << ans << '\n';
        }
    }
}