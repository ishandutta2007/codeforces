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
    int T;
    cin >> T;
    rep(t, T){
        int N, K;
        cin >> N >> K;
        ll a[N];
        rep(i, N) cin >> a[i];
        ll ans = 0;
        sort(a, a+N);
        int b[K];
        rep(i, K) cin >> b[i];
        sort(b, b+K);
        int cnt = 0;
        rep(i, K){
            if(b[i] > 1) break;
            ans += 2*a[N-1-i]; 
            cnt++;
        }
        int now = 0;
        rep3(i, K-1, cnt){
            ans += a[now] + a[N-cnt-(K-i)];
            now += b[i]-1;
        }
        cout << ans << endl;
    }
}