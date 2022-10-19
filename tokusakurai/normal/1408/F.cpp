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
    vector<pii> ans;
    int k = 0;
    while(1<<(k+1) < N) k++;
    rep(i, k){
        rep(j, 1<<k){
            if(j&(1<<i)) continue;
            ans.eb(1+j, 1+j+(1<<i));
        }
    }
    rep(i, k){
        rep(j, 1<<k){
            if(j&(1<<i)) continue;
            ans.eb(N-j-(1<<i), N-j);
        }
    }
    cout << sz(ans) << endl;
    for(auto &e: ans) cout << e.first << ' ' << e.second << endl;
}