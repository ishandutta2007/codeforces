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
    int T;
    cin >> T;
    while(T--){
        int H, W;
        cin >> H >> W;
        vector<string> S(H);
        rep(i, H) cin >> S[i];

        vector<vector<int>> cnt(H, vector<int>(W+1, 0));
        rep(i, H){
            rep(j, W){
                cnt[i][j+1] = cnt[i][j];
                if(S[i][j] == '*') cnt[i][j+1]++;
            }
        }

        ll ans = 0;
        rep(i, H){
            rep(j, W){
                int k = 0;
                while(true){
                    int x = i+k, l = j-k, r = j+k;
                    if(x >= H || l < 0 || r >= W) break;
                    int s = cnt[x][r+1]-cnt[x][l];
                    if(s == r-l+1) k++;
                    else break;
                }
                ans += k;
            }
        }

        cout << ans << '\n';
    }
}