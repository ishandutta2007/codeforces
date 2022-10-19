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
    int N;
    cin >> N;
    int a[N];
    rep(i, N) cin >> a[i];
    sort(a, a+N);
    int ans[N];
    rep(i, N){
        if(i < N/2) ans[2*i+1] = a[i];
        else ans[2*(i-N/2)] = a[i];
    }
    int cnt = 0;
    rep2(i, 1, N-2){
        if(ans[i-1] > ans[i] && ans[i] < ans[i+1]) cnt++;
    }
    cout << cnt << endl;
    rep(i, N) cout << ans[i] << ' '; cout << endl;
}