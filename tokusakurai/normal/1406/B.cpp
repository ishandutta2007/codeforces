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
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        ll a[N];
        rep(i, N) cin >> a[i];
        ll dp1[N+1][6], dp2[N+1][6];
        fill(dp1[0], dp1[N+1], -INF), fill(dp2[0], dp2[N+1], INF);
        dp1[0][0] = 1, dp2[0][0] = 1;
        rep(i, N){
            rep(j, 6){
                if(dp1[i][j] == -INF || dp2[i][j] == INF) continue;
                chmax(dp1[i+1][j], dp1[i][j]), chmin(dp2[i+1][j], dp2[i][j]);
                if(j == 5) continue;
                if(a[i] >= 0){
                    chmax(dp1[i+1][j+1], dp1[i][j]*a[i]);
                    chmin(dp2[i+1][j+1], dp2[i][j]*a[i]);
                }
                if(a[i] <= 0){
                    chmax(dp1[i+1][j+1], dp2[i][j]*a[i]);
                    chmin(dp2[i+1][j+1], dp1[i][j]*a[i]);
                }
            }
        }
        cout << dp1[N][5] << endl;
    }
}