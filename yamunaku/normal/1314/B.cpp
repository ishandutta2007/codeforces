//
// Created by yamunaku on 2020/02/24.
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

int main(){
    CFS;
    int n, k;
    cin >> n >> k;
    vi a(1 << n, 0);
    int x;
    rep(i, k){
        cin >> x;
        a[x - 1] = 1;
    }
    int m = 1 << (n - 2);
    mti dp(2 * m, vi(4, -IINF));
    for(int i = 0; 1; i += 4){
        if(i + 3 >= (1 << n)) break;
        int c = 0;
        rep(j, 4) if(a[i + j]) c++;
        if(c == 0) dp[i / 4 + m - 1][0] = 0;
        else if(c == 1) dp[i / 4 + m - 1][1] = 1, dp[i / 4 + m - 1][2] = 2;
        else if(c >= 2) dp[i / 4 + m - 1][3] = 3;
//        rep(j, 4) cout << dp[i / 4 + m - 1][j] << " ";
//        cout << endl;
    }
    per(i, m - 1){
        int lc = 2 * i + 1, rc = 2 * i + 2;
        rep(x, 4){
            rep(y, 4){
                if(dp[lc][x] < 0 || dp[rc][y] < 0) continue;
                dp[i][x | y] = max(dp[i][x | y], dp[lc][x] + dp[rc][y] + (x | y));
            }
        }
//        rep(j, 4) cout << dp[i][j] << " ";
//        cout << endl;
    }
    int p = 0;
    for(int i = 0; i < (1 << n); i += 2){
        if(i + 1 >= (1 << n)) break;
        if(a[i] || a[i + 1]) p++;
    }
    int ans = 0;
    rep(i, 4) ans = max(ans, dp[0][i] + (i ? 1 : 0));
    cout << ans + p << endl;
    return 0;
}