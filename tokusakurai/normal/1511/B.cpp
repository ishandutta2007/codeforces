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

    vector<ll> pw1(12, 1), pw2(40, 1), pw3(30, 1);
    rep(i, 11) pw1[i+1] = pw1[i]*10;
    rep(i, 39) pw2[i+1] = pw2[i]*2;
    rep(i, 29) pw3[i+1] = pw3[i]*3;

    while(T--){
        int a, b, c; cin >> a >> b >> c;

        a -= c-1, b -= c-1;
        ll A, B;

        each(e, pw2){
            if(e == 1) continue;
            if(sz(to_string(e)) == a){
                A = e; break;
            }
        }
        each(e, pw3){
            if(e == 1) continue;
            if(sz(to_string(e)) == b){
                B = e; break;
            }
        }

        cout << A*pw1[c-1] << ' ' << B*pw1[c-1] << '\n';
    }
}