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
    vector<int> N(4);
    rep(i, 4) cin >> N[i];

    vector<vector<int>> v(4);
    rep(i, 4){
        v[i].resize(N[i]);
        rep(j, N[i]) cin >> v[i][j];
    }

    vector<vector<vector<int>>> ng(3);
    rep(i, 3){
        int M; cin >> M;
        ng[i].resize(N[i+1]);
        rep(j, M){
            int a, b; cin >> a >> b; a--, b--;
            ng[i][b].eb(a);
        }
    }

    vector<int> dp(N[0], inf);
    rep(i, N[0]) dp[i] = v[0][i];

    rep(i, 3){
        vector<int> tmp(N[i+1], inf);
        multiset<int> s;
        each(e, dp) s.emplace(e);

        rep(j, N[i+1]){
            each(e, ng[i][j]){
                auto it = s.find(dp[e]);
                s.erase(it);
            }
            if(!s.empty() && *s.begin() != inf) tmp[j] = v[i+1][j]+*s.begin();
            each(e, ng[i][j]){
                s.emplace(dp[e]);
            }
        }

        swap(dp, tmp);
    }

    int ans = *min_element(all(dp));

    cout << (ans == inf? -1 : ans) << '\n';
}