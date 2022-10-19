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
        vector<vector<int>> a(H, vector<int>(W, 0));
        rep(i, H){
            rep(j, W) cin >> a[i][j];
        }
        int ans = 0;
        vector<int> cnt1(H+W-1, 0), cnt2(H+W-1, 0);
        rep(i, H){
            rep(j, W){
                (a[i][j] == 0? cnt1 : cnt2)[min(i+j, H+W-2-i-j)]++;
            }
        }
        rep(i, H+W-1){
            if((H+W-2)%2 == 0 && i == (H+W-2)/2) continue;
            ans += min(cnt1[i], cnt2[i]);
        }
        cout << ans << '\n';
    }
}