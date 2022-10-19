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

struct query{
    int i, j, x;
    query(int i, int j, int x) : i(i), j(j), x(x) {}
};

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        ll a[N+1], s = 0;
        rep2(i, 1, N) {cin >> a[i]; s += a[i];}
        if(s%N != 0) {cout << -1 << endl; continue;}
        int k = s/N;
        vector<query> ans;
        rep2(i, 2, N){
            if(a[i]%i == 0){
                ans.eb(i, 1, a[i]/i);
            }
            else{
                ans.eb(1, i, i-(a[i]%i));
                ans.eb(i, 1, 1+a[i]/i);
            }
        }
        rep2(i, 2, N){
            ans.eb(1, i, k);
        }
        cout << sz(ans) << endl;
        for(auto &e: ans){
            cout << e.i << ' ' << e.j << ' ' << e.x << endl;
        }
    }
}