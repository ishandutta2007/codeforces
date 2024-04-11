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
    int T; cin >> T;

    vector<vector<int>> ok;
    vector<int> s;

    rep(i, 8){
        rep(j, i){
            vector<int> tmp;
            int now = 4;

            rep(k, 8){
                if(k == i || k == j) now += 3, now %= 10;
                else tmp.eb(now);
            }

            ok.eb(tmp), s.eb(accumulate(all(tmp), 0));
        }
    }

    while(T--){
        ll N; cin >> N;
        string S = to_string(N);
        reverse(all(S));
        int n = sz(S);

        vector<vector<bool>> dp(n+1, vector<bool>(10, false));
        vector<vector<pii>> pre(n+1, vector<pii>(10));
        dp[0][0] = true;

        rep(i, n){
            rep(j, 10){
                if(dp[i][j] == false) continue;
                int x = S[i]-'0';

                rep(k, sz(s)){
                    int p = j+s[k];

                    if(p%10 == x){
                        dp[i+1][p/10] = true;
                        pre[i+1][p/10] = pii(j, k);
                    }
                }
            }
        }

        if(!dp[n][0]) {cout << "-1\n"; continue;}

        int j = 0;
        vector<string> ans(6);

        rep3(i, n, 1){
            auto [nj, nk] = pre[i][j];

            rep(k, 6){
                ans[k] += char('0'+ok[nk][k]);
            }

            j = nj;
        }

        rep(i, 6){
            int j = 0;
            while(j < sz(ans[i])-1 && ans[i][j] == '0') j++;
            cout << ans[i].substr(j) << (i == 5? '\n' : ' ');
        }
    }
}