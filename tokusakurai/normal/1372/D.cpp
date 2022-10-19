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
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N;
    cin >> N;
    ll a[N];
    rep(i, N) cin >> a[i];
    if(N == 1) {cout << a[0] << endl; return 0;}
    ll ans[N];
    ans[0] = 0;
    rep(i, N) if(i%2 == 0) ans[0] += a[i];
    ans[1] = a[0];
    rep(i, N) if(i&1) ans[1] += a[i];
    rep2(i, 2, N-1){
        ans[i] = ans[i-2]-a[i-2]+a[i-1];
    }
    ll M = 0;
    rep(i, N) chmax(M, ans[i]);
    cout << M << endl;
}