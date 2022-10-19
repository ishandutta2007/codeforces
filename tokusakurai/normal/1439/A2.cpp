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
        int s[H+1][W+1];
        rep(i, H) rep(j, W) s[i+1][j+1] = S[i][j]-'0';
        vector<pii> ans;
        if(W&1){
            rep3(i, H, 1){
                if(s[i][W] == 0) continue;
                if(i > 1){
                    ans.eb(i, W), ans.eb(i, W-1), ans.eb(i-1, W);
                    s[i][W] ^= 1, s[i][W-1] ^= 1, s[i-1][W] ^= 1;
                }
                else{
                    ans.eb(i, W), ans.eb(i, W-1), ans.eb(i+1, W-1);
                    s[i][W] ^= 1, s[i][W-1] ^= 1, s[i+1][W-1] ^= 1;
                }
            }
        }
        if(H&1){
            rep3(j, W&~1, 1){
                if(s[H][j] == 0) continue;
                if(j > 1){
                    ans.eb(H, j), ans.eb(H-1, j), ans.eb(H, j-1);
                    s[H][j] ^= 1, s[H-1][j] ^= 1, s[H][j-1] ^= 1;
                }
                else{
                    ans.eb(H, j), ans.eb(H-1, j), ans.eb(H-1, j+1);
                    s[H][j] ^= 1, s[H-1][j] ^= 1, s[H-1][j+1] ^= 1;
                }
            }
        }
        rep(i, H/2) rep(j, W/2){
            int x = 2*i+1, y = 2*j+1;
            vector<pii> zero, one;
            rep(a, 2) rep(b, 2){
                if(s[x+a][y+b] == 0) zero.eb(x+a, y+b);
                else one.eb(x+a, y+b);
            }
            if(sz(one) == 0) continue;
            if(sz(one) == 1){
                auto [p, q] = one[0];
                int a = (p == 1? 1 : -1), b = (q == 1? 1 : -1);
                ans.eb(p, q), ans.eb(p+a, q), ans.eb(p, q+b);
                ans.eb(p, q), ans.eb(p+a, q), ans.eb(p+a, q+b);
                ans.eb(p, q), ans.eb(p, q+b), ans.eb(p+a, q+b);
            }
            if(sz(one) == 2){
                rep(a, 2){
                    rep(b, 2) ans.eb(zero[b]);
                    ans.eb(one[a]);
                }
            }
            if(sz(one) == 3){
                each(e, one) ans.eb(e);
            }
            if(sz(one) == 4){
                rep(a, 2) rep(b, 2){
                    rep(c, 2) rep(d, 2){
                        if(c != a || d != b) ans.eb(x+c, y+d);
                    }
                }
            }
        }
        /*
        rep(i, H) rep(j, W){
            if(S[i][j] == '0') continue;
            int a = (i == 0? 1 : -1), b = (j == 0? 1 : -1);
            ans.eb(i, j), ans.eb(i+a, j), ans.eb(i, j+b);
            ans.eb(i, j), ans.eb(i+a, j), ans.eb(i+a, j+b);
            ans.eb(i, j), ans.eb(i, j+b), ans.eb(i+a, j+b);
        }
        */
        cout << sz(ans)/3 << '\n';
        rep(i, sz(ans)/3){
            rep(j, 3){
                cout << ans[3*i+j].first << ' ' << ans[3*i+j].second << ' ';
            }
            cout << '\n';
        }
    }
}