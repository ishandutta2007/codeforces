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
        ll x, y; cin >> x >> y;

        ll ans = 0;

        ll m = 0, k = 1;
        while(m*m < x) m++;

        for(; k <= y; k++){
            ll tmp = x/(k+1);
            if(tmp <= k-1) break;
            ans += k-1;
        }

        for(; k <= y; k++){
            ll tmp = x/(k+1);
            if(tmp < m) break; 
        }

        for(ll i = 1; i < m; i++){
            ll L = x/(i+1)-1, R = x/i-1; //(L,R]
            chmax(L, k-1), chmin(R, y);

            ans += i*max(R-L, 0LL);
        }

        cout << ans << '\n';
    }
}