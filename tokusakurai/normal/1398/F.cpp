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
    int N; string S; cin >> N >> S;

    vector<vector<int>> dp(N+1, vector<int>(2, 0));
    rep3(i, N-1, 0){
        if(S[i] != '1') dp[i][0] = dp[i+1][0]+1;
        if(S[i] != '0') dp[i][1] = dp[i+1][1]+1;
    }

    vector<int> c(N+1);
    rep(i, N+1) c[i] = max(dp[i][0], dp[i][1]);

    vector<vector<int>> ids(N+1);

    rep(i, N+1){
        ids[c[i]].eb(i);
    }
    set<int> s;
    s.emplace(N);

    vector<int> ans(N+1);

    rep3(i, N, 1){
        each(e, ids[i]) s.emplace(e);
        int p = 0;
        while(p < N){
            if(c[p] >= i) p += i, ans[i]++;
            else p = *s.upper_bound(p);
        }
    }

    rep2(i, 1, N) cout << ans[i] << (i == N? '\n' : ' ');
}