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
        int N;
        cin >> N;
        int a[N], b[N];
        rep(i, N) cin >> a[i];
        bool used[N];
        fill(used, used+N, false);
        int M = 0, id = -1;
        rep(i, N) if(chmax(M, a[i])) id = i;
        int g = a[id];
        b[0] = a[id], used[id] = true;
        rep2(i, 1, N-1){
            M = 0, id = -1;
            rep(j, N){
                if(used[j]) continue;
                if(chmax(M, gcd(g, a[j]))) id = j;
            }
            b[i] = a[id], used[id] = true, g = gcd(g, a[id]);
        }
        rep(i, N) cout << b[i] << ' '; cout << endl;
    }
}