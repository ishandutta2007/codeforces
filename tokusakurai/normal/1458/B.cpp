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
    int N; cin >> N;

    vector<int> b(N), a(N);
    rep(i, N) cin >> a[i] >> b[i];
    int S = accumulate(all(b), 0);

    int MAX = 10000;
    vector<vector<int>> dp(N+1, vector<int>(MAX+1, -inf));

    dp[0][0] = 0;
    rep(i, N){
        rep3(j, i, 0){
            rep3(k, MAX, 0){
                if(dp[j][k] == -inf) continue;
                chmax(dp[j+1][k+a[i]], dp[j][k]+b[i]);
            }
        }
    }

    rep2(i, 1, N){
        int ans = -inf;
        rep2(j, 0, MAX){
            chmax(ans, min(j*2, S+dp[i][j]));
        }
        if(ans%2 == 0) cout << ans/2 << ".0000000000 ";
        else cout << ans/2 << ".5000000000 ";
    }
    cout << '\n';
}