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
        vector<ll> a(N);
        rep(i, N) cin >> a[i];
        vector<ll> s(N+1);
        rep(i, N){
            s[i+1] = s[i];
            if(i&1) s[i+1] += a[i];
            else s[i+1] -= a[i];
        }
        vector<ll> M1(N+2), M2(N+2);
        M1[N+1] = M2[N+1] = -INF;
        rep3(i, N, 0){
            M1[i] = M1[i+1], M2[i] = M2[i+1];
            if(i&1) chmax(M1[i], s[i]);
            else chmax(M2[i], s[i]);
        }

        ll base = 0;
        rep(i, N) if(i%2 == 0) base += a[i];
        ll ans = 0;
        rep(i, N+1){
            if(i&1) chmax(ans, M1[i]-s[i]);
            else chmax(ans, M2[i]-s[i]);
        }

        cout << base+ans << '\n';
    }
}