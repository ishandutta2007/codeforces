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
        int N; cin >> N;

        vector<ll> a(N+1), b(N+1);
        a[0] = 1, b[0] = 0;
        rep2(i, 1, N) cin >> a[i];
        rep2(i, 1, N) {cin >> b[i]; b[i] = a[i]-b[i];}

        vector<int> p(N+1);
        iota(all(p), 0);
        sort(all(p), [&](int i, int j){
            return a[i] < a[j];
        });

        ll ans = 0;

        rep(i, N){
            int u = p[i], v = p[i+1];
            ll d = b[v]-b[u];
            if(d == 0 && b[u]%2 == 0) ans += a[v]-a[u];
            if(d%2 == 0) ans += d/2;
            else if(b[u]%2 == 1) ans += (d+1)/2;
            else ans += (d-1)/2;
        }

        cout << ans << '\n';
    }
}