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
        int N; ll u, v; cin >> N >> u >> v;

        vector<int> a(N);
        rep(i, N) cin >> a[i];

        bool flag = false;
        rep(i, N-1){
            if(abs(a[i]-a[i+1]) > 1) flag = true;
        }

        if(flag) {cout << "0\n"; continue;}

        ll ans = INF;
        rep(i, N-1){
            if(i > 0 && a[i-1] != a[i]) flag = true;
            if(i < N-1 && a[i] != a[i+1]) flag = true;
        }

        chmin(ans, u+(flag? 0 : v));
        int MAX = 1000000+1;

        rep(i, N){
            rep2(j, -10, 10){
                if(a[i]+j < 0 || a[i]+j > MAX) continue;
                int k = a[i]+j;

                bool U = false, D = false;
                if(i > 0 && abs(a[i-1]-k) > 1) U = true;
                if(i < N-1 && abs(a[i+1]-k) > 1) D = true;

                if(U || D) chmin(ans, v*abs(j));
            }
        }

        cout << ans << '\n';
    }
}