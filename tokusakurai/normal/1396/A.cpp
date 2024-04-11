#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
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
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    ll N;
    cin >> N;
    ll a[N];
    rep(i, N) cin >> a[i];
    if(N == 1){
        rep(i, 2) cout << 1 << ' ' << 1 << endl << 0 << endl;
        cout << 1 << ' ' << 1 << endl << -a[0] << endl;
        return 0;
    }
    ll x[N], y[N];
    rep(i, N-1){
        ll tmp = a[i]+N*inf;
        y[i] = tmp%N;
        x[i] = (y[i]-a[i])/N-y[i];
    }
    ll tmp = a[N-1]+N*inf;
    y[N-1] = -(tmp%N);
    x[N-1] = (-y[N-1]-a[N-1])/N;
    cout << 1 << ' ' << N-1 << endl;
    rep(i, N-1) cout << y[i]*(N-1) << ' '; cout << endl;
    cout << N << ' ' << N << endl;
    cout << y[N-1] << endl;
    cout << 1 << ' ' << N << endl;
    rep(i, N) cout << x[i]*N << ' '; cout << endl;
}