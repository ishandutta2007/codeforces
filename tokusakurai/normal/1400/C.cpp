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
        string S; int t;
        cin >> S >> t;
        int N = sz(S);
        int ans[N];
        fill(ans, ans+N, 1);
        rep(i, N){
            if(S[i] == '1') continue;
            if(i+t < N) ans[i+t] = 0;
            if(i-t >= 0) ans[i-t] = 0;
        }
        bool res = true;
        rep(i, N){
            if(S[i] == '0') continue;
            res &= ((i+t < N && ans[i+t]) || (i-t >= 0 && ans[i-t]));
        }
        if(!res) cout << -1 << endl;
        else{
            rep(i, N) cout << ans[i]; cout << endl;
        }
    }
}