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
        ll N; cin >> N;

        ll ans = (N-1)*(N-1);
        rep2(i, 1, N-2){
            ll d = max((ll)i, N-1-i);
            ans += d*d;
        }
        cout << ans << '\n';

        vector<int> p(N);

        p[0] = N/2;
        rep2(i, N/2, N-2) p[i] = i+1;
        rep2(i, 1, N/2-1) p[i] = i-1;
        p[N-1] = N/2-1;

        rep(i, N) cout << p[i]+1 << ' '; cout << '\n';

        cout << N-1 << '\n';
        rep2(i, N/2, N-2){
            cout << i+1 << ' ' << 1 << '\n';
        }
        rep3(i, N/2-1, 1){
            cout << i+1 << ' ' << N << '\n';
        }
        cout << 1 << ' ' << N << '\n';
    }
}