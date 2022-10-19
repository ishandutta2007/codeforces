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
    int R, N; cin >> R >> N;

    vector<int> t(N+1), x(N+1), y(N+1);
    t[0] = 0, x[0] = 0, y[0] = 0;
    rep2(i, 1, N){
        cin >> t[i] >> x[i] >> y[i]; x[i]--, y[i]--;
    }

    vector<int> dp(N+1, -inf);
    int M = -inf;
    dp[0] = 0;

    rep2(i, 1, N){
        rep2(j, max(i-1000, 0), i-1){
            int D = abs(x[i]-x[j])+abs(y[i]-y[j]);
            if(D <= t[i]-t[j]) chmax(dp[i], dp[j]+1);
        }
        chmax(dp[i], M+1);
        if(i-1000 >= 0) chmax(M, dp[i-1000]);
    }

    cout << *max_element(all(dp)) << '\n';
}