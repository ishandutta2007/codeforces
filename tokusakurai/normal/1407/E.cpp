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

    vector<vector<pii>> es(N);

    rep(i, M){
        int u, v, c; cin >> u >> v >> c; u--, v--;
        es[v].eb(u, c);
    }

    vector<int> col(N, -1), d(N, inf);

    queue<int> que;
    d[N-1] = 0, que.emplace(N-1);

    while(!que.empty()){
        int i = que.front(); que.pop();
        each(e, es[i]){
            auto [j, c] = e;
            if(d[j] <= d[i]+1) continue;
            if(col[j] == -1) col[j] = c^1;
            else if(col[j] != c) continue;
            else d[j] = d[i]+1, que.emplace(j);
        }
    }

    cout << (d[0] == inf? -1 : d[0]) << '\n';
    rep(i, N) cout << (col[i] == 1? '1' : '0');
    cout << '\n';
}