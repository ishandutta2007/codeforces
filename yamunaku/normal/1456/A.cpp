//
// Created by yamunaku on 2020/11/29.
//

#include <bits/stdc++.h>
//#include <atcoder/all>

using namespace std;
//using namespace atcoder;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

void solve() {
    ll n, p, k;
    cin >> n >> p >> k;
    p--;
    string s;
    cin >> s;
    ll x, y;
    cin >> x >> y;
    vl dp(n, LINF);
    ll ans = LINF;
    perl(i, p, n) {
        if (i + k >= n) {
            dp[i] = 0;
        } else {
            dp[i] = dp[i + k];
        }
        if (s[i] == '0') {
            dp[i]++;
        }
//        cout << i SP dp[i] SP i * y + dp[i] * x << endl;
        ans = min(ans, (i - p) * y + dp[i] * x);
    }
    cout << ans << endl;
}

int main() {
    //CFS;
    int t;
    cin >> t;
    rep(_, t) solve();
    return 0;
}