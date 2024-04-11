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

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<int> dp(N, 0);
    int ans = 0;

    rep3(i, M-1, 0){
        vector<int> tmp(N, 0);
        rep(j, N){
            tmp[j] = (S[j][i] == '0'? 0 : 1+dp[j]);
        }

        swap(dp, tmp);

        vector<int> cnt(M+1, 0);
        rep(j, N) cnt[dp[j]]++;

        vector<int> a;
        rep3(j, M, 0){
            while(cnt[j]--) a.eb(j);
        }

        rep(i, N){
            chmax(ans, (i+1)*a[i]);
        }
    }

    cout << ans << '\n';
}