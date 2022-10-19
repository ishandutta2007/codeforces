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
    ll A, B; cin >> A >> B;

    if(B == 0){
        cout << A*A << '\n';
        cout << string(A, 'o') << '\n';
        return 0;
    }
    if(A == 0){
        cout << -B*B << '\n';
        cout << string(B, 'x') << '\n';
        return 0;
    }

    ll ans = -INF;
    ll a = -1, b = -1;

    rep2(i, 1, A){
        rep2(j, i-1, i+1){
            if(j == 0 || j > B) continue;
            ll tmp = i-1+(A-i+1)*(A-i+1);
            ll y = B%j, x = j-y, c = B/j;
            tmp -= c*c*x+(c+1)*(c+1)*y;

            if(chmax(ans, tmp)){
                a = i, b = j;
            }
        }
    }

    vector<string> X, Y;
    rep(i, a-1) X.eb("o");
    X.eb(A-a+1, 'o');

    int y = B%b, x = b-y;
    rep(i, x) Y.eb(B/b, 'x');
    rep(i, y) Y.eb(B/b+1, 'x');

    cout << ans << '\n';
    if(b == a+1){
        rep(i, a){
            cout << Y[i] << X[i];
        }
        cout << Y[b-1] << '\n';
    }
    if(b == a){
        rep(i, a){
            cout << Y[i] << X[i];
        }
        cout << '\n';
    }
    if(b == a-1){
        rep(i, b){
            cout << X[i] << Y[i];
        }
        cout << X[a-1] << '\n';
    }
}