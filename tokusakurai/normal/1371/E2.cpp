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
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll N, P;
    cin >> N >> P;
    ll a[N];
    ll M = 0;
    rep(i, N){
        cin >> a[i];
        chmax(M, a[i]);
    }
    ll n = (N+P-1)/P;
    n *= P;
    int cnt[N+1];
    fill(cnt, cnt+N+1, 0);
    rep(i, N){
        if(a[i] <= M-N) cnt[0]++;
        else cnt[a[i]-(M-N)]++;
    }
    rep2(i, 1, N) cnt[i] += cnt[i-1];
    int res[P];
    fill(res, res+P, 0);
    rep(i, N+1){
        int k = cnt[i]%P;
        if(i-k >= 0) res[(i-k)%P] = i-k;
    }
    bool ans[N+1];
    fill(ans, ans+N+1, true);
    rep(i, P){
        for(int j = i; j <= res[i]; j += P){
            ans[j] = false;
        }
    }
    int sum = 0;
    rep2(i, 0, N){
        ans[i] &= i < P;
        sum += ans[i];
    }
    cout << sum << endl;
    rep2(i, 0, N) if(ans[i]) cout << M-N+i << ' '; cout << endl;
}