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
        int N; ll W;
        cin >> N >> W;
        ll K = (W+1)/2;
        vector<ll> w(N);
        rep(i, N) cin >> w[i];

        bool flag = false;
        rep(i, N){
            if(K <= w[i] && w[i] <= W){
                cout << 1 << '\n' << i+1 << '\n';
                flag = true;
                break;
            }
        }
        if(flag) continue;

        ll now = 0;
        vector<int> ans;
        rep(i, N){
            if(w[i] < K){
                now += w[i], ans.eb(i+1);
                if(now >= K) break;
            }
        }

        if(now < K) {cout << -1 << '\n'; continue;}
        cout << sz(ans) << '\n';
        each(e, ans) cout << e << ' '; cout << '\n';
    }
}