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
    int T;
    cin >> T;
    while(T--){
        ll N;
        cin >> N;
        ll cnt[N][N+1];
        rep(i, N) cnt[i][0] = 0;
        int a[N];
        rep(i, N){
            cin >> a[i]; a[i]--;
            rep(j, N) cnt[j][i+1] = cnt[j][i];
            cnt[a[i]][i+1]++;
        }
        ll ans = 0;
        rep2(i, 0, N-1){
            rep2(j, i+1, N-1){
                ans += cnt[a[j]][i]*(cnt[a[i]][N]-cnt[a[i]][j+1]);
            }
        }
        cout << ans << endl;
    }
}