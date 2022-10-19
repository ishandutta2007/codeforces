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

int judge(string S, string T){
    int ret = 0;
    rep(i, 7){
        if(S[i] == '1' && T[i] == '0') return -1;
        if(S[i] == '0' && T[i] == '1') ret++;
    }
    return ret;
}

int main(){
    int N, K;
    cin >> N >> K;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    reverse(all(S));

    vector<string> T = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    vector<vector<int>> dp(N+1, vector<int>(K+1, -inf));

    dp[0][0] = -1;
    rep(i, N){
        rep(j, K+1){
            if(dp[i][j] == -inf) continue;
            rep(k, 10){
                int tmp = judge(S[i], T[k]);
                if(tmp == -1) continue;
                int nj = j+tmp;
                if(nj <= K) chmax(dp[i+1][nj], k);
            }
        }
    }

    if(dp[N][K] == -inf) {cout << -1 << '\n'; return 0;}

    string ans;
    int now = K;
    rep3(i, N, 1){
        ans += char('0'+dp[i][now]);
        now -= judge(S[i-1], T[dp[i][now]]);
    }

    cout << ans << '\n';
}