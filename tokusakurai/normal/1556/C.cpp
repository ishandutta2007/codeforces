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

    vector<ll> c(N);
    rep(i, N) cin >> c[i];

    rep(i, N){
        if(i&1) c[i] *= -1;
    }

    vector<vector<ll>> dp1(N, vector<ll>(N+1, 0)), dp2(N, vector<ll>(N+1, 0)); //sum min

    rep(i, N){
        rep2(j, i, N-1){
            dp1[i][j+1] = dp1[i][j]+c[j];
            dp2[i][j+1] = min(dp2[i][j], dp1[i][j+1]);
        }
    }

    ll ans = 0;

    rep(j, N){
        rep(i, j){
            if(i%2 == 0 || j%2 == 0) continue;
            ll L = max(-dp2[i][j], -dp1[i][j]), R = min(c[i-1], -c[j]-dp1[i][j]);
            ans += max(0LL, R-L+1);
        }
    }

    rep(i, N/2){
        ans += min(c[2*i], -c[2*i+1]);
    }

    cout << ans << '\n';
}