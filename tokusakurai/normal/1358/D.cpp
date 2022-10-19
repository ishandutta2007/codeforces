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
    ll x;
    cin >> N >> x;
    ll a[N];
    rep(i, N) cin >> a[i];
    vector<ll> cnt1(2*N+1), cnt2(2*N+1);
    cnt1[0] = cnt2[0] = 0;
    rep(i, 2*N){
        int j = i%N;
        cnt1[i+1] = cnt1[i]+a[j];
        cnt2[i+1] = cnt2[i]+a[j]*(a[j]+1)/2;
    }
    ll ans = 0;
    rep2(i, 1, N){
        int s = upper_bound(all(cnt1), cnt1[N+i]-x)-cnt1.begin()-1;
        ll tmp = cnt2[N+i]-cnt2[s], d = cnt1[N+i]-cnt1[s];
        tmp -= (d-x)*(d-x+1)/2;
        chmax(ans, tmp);
    }
    cout << ans << endl;
}