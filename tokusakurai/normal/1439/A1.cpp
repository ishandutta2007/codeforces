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
        string S[H];
        rep(i, H) cin >> S[i];
        vector<pii> ans;
        rep(i, H) rep(j, W){
            if(S[i][j] == '0') continue;
            int a = (i == 0? 1 : -1), b = (j == 0? 1 : -1);
            ans.eb(i, j), ans.eb(i+a, j), ans.eb(i, j+b);
            ans.eb(i, j), ans.eb(i+a, j), ans.eb(i+a, j+b);
            ans.eb(i, j), ans.eb(i, j+b), ans.eb(i+a, j+b);
        }
        cout << sz(ans)/3 << '\n';
        rep(i, sz(ans)/3){
            rep(j, 3){
                cout << ans[3*i+j].first+1 << ' ' << ans[3*i+j].second+1 << ' ';
            }
            cout << '\n';
        }
    }
}