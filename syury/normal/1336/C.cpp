//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb emplace_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = 3333;
const int mod = 998244353;

string s, t;
int n, m;
ll dp[N][N];
ll suff[N][N];

inline void add(ll& x, ll y){
    x += y;
    x -= x >= mod ? mod : 0;
}

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;
    n = s.length();
    m = t.length();
    if(n < m){cout << 0; ret 0;}
    E(dead, 0, n)suff[0][dead] = n + 1 - dead;
    E(len, 1, m){
        DF(dead, n - 1, 0){
            add(suff[len][dead], suff[len][dead + 1]);
            if(s[dead] == t[len - 1])
                add(suff[len][dead], suff[len - 1][dead + 1]);
        }
    }
    F(i, 0, m)
        if(t[i] == s[0])dp[1][i] = 1;
    ll ans = 0;
    F(len, 1, m){
        F(i, 0, m - len + 1){
            if(i + len == m){
                add(ans, dp[len][i] * 1ll * suff[m - len][len] % mod);
                cont;
            }
            if(s[len] == t[i + len])
                add(dp[len + 1][i], dp[len][i]);
            if(i && s[len] == t[i - 1])
                add(dp[len + 1][i - 1], dp[len][i]);
        }
    }
    //cout << suff[m][1] << endl;
    add(ans, suff[m][1]);
    ll pw = 1;
    E(len, 2, n){
        //cout << "adding " << pw * suff[m][len] << endl;
        add(ans, pw * suff[m][len] % mod);
        add(pw, pw);
    }
    add(ans, dp[m][0] * suff[0][m] % mod);
    cout << ans*2%mod << endl;
    return 0;
}