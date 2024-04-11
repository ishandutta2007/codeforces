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

struct Random_Number_Generator{
    mt19937_64 mt;

    Random_Number_Generator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

    int64_t operator () (int64_t l, int64_t r){
        uniform_int_distribution<int64_t> dist(l, r-1);
        return dist(mt);
    }

    int64_t operator () (int64_t r){ 
        return (*this)(0, r);
    }
};

Random_Number_Generator rng;

int main(){
    int N; cin >> N;

    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    int T = 13;
    ll ans = 1;

    while(T--){
        int i = rng(0, N);
        map<ll, int> mp;
        rep(j, N){
            mp[gcd(a[j], a[i])]++;
        }

        vector<pli> ps;
        each(e, mp) ps.eb(e);
        reverse(all(ps));

        int n = sz(ps);

        rep(i, n){
            int K = 0;
            rep(j, i+1){
                if(ps[j].first%ps[i].first == 0){
                    K += ps[j].second;
                }
            }
            if(K >= (N+1)/2){
                chmax(ans, ps[i].first);
                break;
            }
        }
    }

    cout << ans << '\n';
}