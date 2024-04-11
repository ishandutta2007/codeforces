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

        vector<string> S(H, string(W, '0'));
        rep(j, W){
            if(j%2 == 0) S[0][j] = '1';
        }
        rep(i, H){
            if(i%2 == 0) S[i][0] = '1';
        }
        rep2(j, 1, W-2){
            if(j%2 == 0) S[H-1][j] = '1';
        }
        rep2(i, 1, H-2){
            if(i%2 == 0) S[i][W-1] = '1';
        }

        if(H%2 == 0 && W%2 == 0){
            S[H-1][W-2] = '0';
        }
        if(H%2 == 1 && W%2 == 1){
            S[H-1][W-1] = '1';
        }

        rep(i, H){
            cout << S[i] << '\n';
        }
    }
}