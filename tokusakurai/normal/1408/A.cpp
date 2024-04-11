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
        int a[3][N];
        rep(i, 3){
            rep(j, N) cin >> a[i][j];
        }
        int p[N];
        p[0] = a[0][0];
        rep2(i, 1, N-2){
            rep(j, 3) if(a[j][i] != p[i-1]) p[i] = a[j][i];
        }
        rep(i, 3){
            if(a[i][N-1] != p[N-2] && a[i][N-1] != p[0]) p[N-1] = a[i][N-1];
        }
        rep(i, N) cout << p[i] << ' '; cout << endl;
    }
}