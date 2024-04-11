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
        ll h, c, t;
        cin >> h >> c >> t;
        ll a = t-c, b = h-t;
        if(a <= b) {cout << 2 << '\n'; continue;}
        /*
        double x = double(a)/double(b);
        x -= 1.0;
        x = 1.0/x;
        int k = floor(x);

        int ans = 0;
        double now = 1e10, A = double(b)/double(a+b);
        double EPS = 1e-10;
        rep2(i, k-100, k+100){
            if(i < 0) continue;
            double B = double(i)/double(2*i+1);
            double d = abs(B-A);
            if(B > A) d += EPS;
            if(chmin(now, d)) ans = i;
        }

        cout << 2*ans+1 << '\n';
        */

        ll k = b/(a-b);
        ll l = (-(k*a)+(k+1)*b)*(2*k+3);
        ll r = ((k+1)*a-(k+2)*b)*(2*k+1);
        if(l <= r) cout << 2*k+1 << '\n';
        else cout << 2*k+3 << '\n';
    }
}