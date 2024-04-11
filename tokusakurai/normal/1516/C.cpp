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

    vector<int> a(N);
    rep(i, N) cin >> a[i];
    int S = accumulate(all(a), 0);
    if(S&1) {cout << "0\n"; return 0;}

    S >>= 1;
    vector<vector<bool>> dp(N+1, vector<bool>(S+1, false));
    dp[0][0] = true;

    rep(i, N){
        rep(j, S+1){
            if(dp[i][j]){
                dp[i+1][j] = true;
                if(j+a[i] <= S) dp[i+1][j+a[i]] = true;
            }
        }
    }

    if(!dp[N][S]) {cout << "0\n"; return 0;}

    vector<int> c(N, 0);
    rep(i, N){
        while(a[i]%2 == 0){
            a[i] >>= 1, c[i]++;
        }
    }

    cout << "1\n" << min_element(all(c))-begin(c)+1 << '\n';
}