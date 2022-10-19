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

        vector<ll> a(N);
        rep(i, N) cin >> a[i];

        ll s1 = 0, s2 = 0, m1 = INF, m2 = INF, k1 = 0, k2 = 0;
        ll ans = INF;

        rep(i, N){
            if(i%2 == 0) s1 += a[i], chmin(m1, a[i]), k1++;
            else s2 += a[i], chmin(m2, a[i]), k2++;

            if(i == 0) continue;

            chmin(ans, m1*(N-k1+1)+(s1-m1) + m2*(N-k2+1)+(s2-m2));
        }

        cout << ans << '\n';
    }
}