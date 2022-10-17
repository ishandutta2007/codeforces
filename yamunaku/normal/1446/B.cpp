//
// Created by yamunaku on 2020/11/15.
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

int main() {
    //CFS;
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    mti dp(n + 1, vi(m + 1, 0));
    int ans = 0;
    repl(i, 1, n + 1) {
        repl(j, 1, m + 1) {
            dp[i][j] = max(0, max(dp[i - 1][j] - 1, dp[i][j - 1] - 1));
            if (s[i - 1] == t[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}