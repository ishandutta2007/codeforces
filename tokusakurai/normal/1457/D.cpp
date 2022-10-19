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
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    rep(i, N-1){
        int x = a[i]^a[i+1];
        if(i-1 >= 0 && a[i-1] > x || i+2 < N && x > a[i+2]) {cout << 1 << '\n'; return 0;}
    }
    int ans = inf;
    rep(i, N-1){
        vector<int> dp1(i+1), dp2(N-1-i);
        dp1[0] = a[i], dp2[0] = a[i+1];
        rep(j, i) dp1[j+1] = dp1[j]^a[i-1-j];
        rep(j, N-2-i) dp2[j+1] = dp2[j]^a[i+2+j];
        rep(j, i+1){
            rep(k, N-1-i){
                if(dp1[j] > dp2[k]) chmin(ans, j+k);
            }
        }
    }
    cout << (ans == inf? -1 : ans) << '\n';
}