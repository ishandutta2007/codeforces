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
        int N;
        cin >> N;
        vector<ll> t(N), x(N);
        rep(i, N) cin >> t[i] >> x[i];

        ll p = 0, g = -INF;
        int ans = 0;
        rep(i, N){
            if(g == -INF) g = x[i];
            ll np;
            if(i == N-1) np = g;
            else if(t[i+1]-t[i] >= abs(g-p)) np = g;
            else if(p < g) np = p+t[i+1]-t[i];
            else np = p-(t[i+1]-t[i]);
            if((p-x[i])*(np-x[i]) <= 0) ans++;
            if(np == g) g = -INF;
            p = np;
        }

        cout << ans << '\n';
    }
}