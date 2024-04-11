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
    int N, M;
    cin >> N >> M;
    int a[N], b[N], c[M], d[M];
    rep(i, N) cin >> a[i] >> b[i];
    rep(i, M) cin >> c[i] >> d[i];
    vector<pii> p;
    rep(i, N){
        rep(j, M){
            int x = max(c[j]+1-a[i], 0);
            int y = max(d[j]+1-b[i], 0);
            p.eb(x, y);
        }
    }
    sort(all(p), greater<pii>());
    int ans = inf, H = 0;
    for(auto &e: p){
        chmin(ans, e.first+H);
        chmax(H, e.second);
    }
    chmin(ans, H);
    cout << ans << endl;
}