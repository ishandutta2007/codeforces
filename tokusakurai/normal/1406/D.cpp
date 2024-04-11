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

void out(ll x){
    if(x >= 0) cout << (x+1)/2 << endl;
    else cout << x/2 << endl;
}

int main(){
    int N;
    cin >> N;
    ll a[N];
    rep(i, N) cin >> a[i];
    ll d[N-1];
    rep(i, N-1) d[i] = a[i+1]-a[i];
    ll base = a[0], sum = 0;
    rep(i, N-1){
        if(d[i] > 0) sum += d[i];
    }
    out(base+sum);
    int Q;
    cin >> Q;
    while(Q--){
        int l, r; ll x; cin >> l >> r >> x; l--;
        if(l == 0) base += x;
        else{
            if(d[l-1] > 0) sum -= d[l-1];
            d[l-1] += x;
            if(d[l-1] > 0) sum += d[l-1];
        }
        if(r != N){
            if(d[r-1] > 0) sum -= d[r-1];
            d[r-1] -= x;
            if(d[r-1] > 0) sum += d[r-1];
        }
        out(base+sum);
    }
}