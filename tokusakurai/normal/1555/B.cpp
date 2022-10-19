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
    
    while(T--){
        int H, W; cin >> H >> W;

        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int X, Y; cin >> X >> Y;

        int ans = inf;
        if(X+(x2-x1) <= H){
            chmin(ans, max(X-x1, 0));
            chmin(ans, max(X-(H-x2), 0));
        }
        if(Y+(y2-y1) <= W){
            chmin(ans, max(Y-y1, 0));
            chmin(ans, max(Y-(W-y2), 0));
        }

        cout << (ans == inf? -1 : ans) << '\n';
    }
}