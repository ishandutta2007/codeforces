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
        vector<int> ids[N];
        rep(i, N) ids[i].pb(-1);
        rep(i, N){
            int a; cin >> a; a--;
            ids[a].pb(i);
        }
        rep(i, N) ids[i].pb(N);
        int res[N];
        rep(i, N){
            res[i] = 0;
            rep(j, sz(ids[i])-1){
                chmax(res[i], ids[i][j+1]-ids[i][j]-1);
            }
        }
        int ans[N];
        fill(ans, ans+N, -1);
        int ptr = N;
        rep(i, N){
            rep2(j, res[i], ptr-1) ans[j] = i+1;
            chmin(ptr, res[i]);
        }
        rep(i, N) cout << ans[i] << ' '; cout << endl;
    }
}