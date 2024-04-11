//
// Created by yamunaku on 2020/08/16.
//

#include <bits/stdc++.h>

using namespace std;

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

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi a(n);
    rep(i, n){
        if(s[i] == 'L') a[i] = 0;
        else a[i] = 1;
    }
    int ans = IINF;
    rep(x, 2){
        rep(y, 2){
            mti dp(2, vi(2, IINF));
            dp[x][y] = (a[0] ^ x) + (a[1] ^ y);
            repl(i, 2, n){
                mti ndp(2, vi(2, IINF));
                ndp[0][1] = min(ndp[0][1], dp[0][0] + (a[i] ^ 1));
                ndp[1][0] = min(ndp[1][0], dp[0][1] + (a[i] ^ 0));
                ndp[1][1] = min(ndp[1][1], dp[0][1] + (a[i] ^ 1));
                ndp[0][0] = min(ndp[0][0], dp[1][0] + (a[i] ^ 0));
                ndp[0][1] = min(ndp[0][1], dp[1][0] + (a[i] ^ 1));
                ndp[1][0] = min(ndp[1][0], dp[1][1] + (a[i] ^ 0));
                dp = ndp;
            }
            if(x == 0){
                if(y == 0){
                    ans = min(ans, dp[0][1]);
                    ans = min(ans, dp[1][1]);
                }else{
                    ans = min(ans, dp[1][0]);
                    ans = min(ans, dp[0][1]);
                    ans = min(ans, dp[1][1]);
                }
            }else{
                if(y == 0){
                    ans = min(ans, dp[0][0]);
                    ans = min(ans, dp[1][0]);
                    ans = min(ans, dp[0][1]);
                }else{
                    ans = min(ans, dp[0][0]);
                    ans = min(ans, dp[1][0]);
                }
            }
        }
    }
    cout << ans << endl;
}

int main(){
    CFS;
    int t;
    cin >> t;
    rep(_, t){
        solve();
    }
    return 0;
}