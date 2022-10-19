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
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N;
    cin >> N;
    int n = (N+1)/2, m = N-n;
    ll a[n], S = 0;
    rep(i, n) {cin >> a[i]; S += a[i];}
    ll x;
    cin >> x;
    ll d[m+1];
    d[0] = 0;
    rep(i, m) d[i+1] = d[i]+(x-a[i]);
    rep(i, m) d[i+1] = min(d[i], d[i+1]);
    rep2(i, 0, m){
        ll base = S+x*i;
        if(base+d[m-i] > 0) {cout << n+i << endl; return 0;}
    }
    cout << -1 << endl;
}