#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 1e6 + 5, mod = 998244353;

int add(int x, int y){
    x += y; if (x >= mod) x -= mod; return x;
}

int sub(int x, int y){
    x -= y; if (x < 0) x += mod; return x;
}

int mul(int x, int y){
    return (ll)x * y % mod;
}

int divisors[N];
int dp[N], prefdp[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    int n; cin >> n;
    if (n == 1){
        cout << 1 << endl;
        return 0;
    }
    if (n == 2){
        cout << 3 << endl;
        return 0;
    }
    ForE(i, 1, n){
        for (int j = 2 * i; j <= n; j += i){
            divisors[j]++;
        }
    }
    dp[0] = 1; prefdp[0] = 1;
    dp[1] = 1; prefdp[1] = 2;
    dp[2] = 3; prefdp[2] = 5;
    ForE(i, 3, n){
        dp[i] = divisors[i];
        dp[i] = add(dp[i], prefdp[i - 1]);
        prefdp[i] = add(prefdp[i - 1], dp[i]);
    }
    cout << dp[n] << endl;
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/