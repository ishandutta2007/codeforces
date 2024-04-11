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

#define hash __hash__

const int N = 1e6 + 5, base = 13, mod = 998244353, modhash = 1000004123;

inline int add(int x, int y){
    x += y; if (x >= mod) x -= mod; return x;
}

inline int sub(int x, int y){
    x -= y; if (x < 0) x += mod; return x;
}

inline int mul(int x, int y){
    return (ll)x * y % mod;
}

inline int addhash(int x, int y){
    x += y; if (x >= modhash) x -= modhash; return x;
}

inline int subhash(int x, int y){
    x -= y; if (x < 0) x += modhash; return x;
}

inline int mulhash(int x, int y){
    return (ll)x * y % modhash;
}

string s[3];

int pwbase[N];
int hash[3][N];

void precalhash(){
    pwbase[0] = 1;
    For(i, 1, N){
        pwbase[i] = mulhash(pwbase[i - 1], base);
    }
    For(j, 0, 3){
        For(i, 1, isz(s[j])){
            hash[j][i] = addhash(mulhash(hash[j][i - 1], base), s[j][i] - '0' + 1);
        }
    }
}

int calhash(int j, int l, int r){
    return subhash(hash[j][r], mulhash(hash[j][l - 1], pwbase[r - l + 1]));
}

int dp[N], sumdp[N];
int l[N], r[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    For(j, 0, 3){
        cin >> s[j]; s[j] = ' ' + s[j];
    }
    precalhash();
    dp[0] = 1; sumdp[0] = 1;
    For(i, 1, isz(s[1]) - 1){
        sumdp[i] = 1;
    }
    For(i, isz(s[1]) - 1, isz(s[0])){
        l[i] = max(1, i - isz(s[2]) + 2);
        if (l[i] == i - isz(s[2]) + 2){
            int lo = 1, hi = isz(s[2]);
            while (lo < hi){
                int mid = (lo + hi) >> 1;
                if (calhash(0, l[i], l[i] + mid - 1) != calhash(2, 1, mid)){
                    hi = mid;
                }
                else{
                    lo = mid + 1;
                }
            }
            if (lo != isz(s[2]) and s[0][l[i] + lo - 1] > s[2][lo]){
                l[i]++;
            }
        }
        r[i] = i - isz(s[1]) + 2;
        if (r[i] == i - isz(s[1]) + 2){
            int lo = 1, hi = isz(s[1]);
            while (lo < hi){
                int mid = (lo + hi) >> 1;
                if (calhash(0, r[i], r[i] + mid - 1) != calhash(1, 1, mid)){
                    hi = mid;
                }
                else{
                    lo = mid + 1;
                }
            }
            if (lo != isz(s[1]) and s[0][r[i] + lo - 1] < s[1][lo]){
                r[i]--;
            }
        }
        if (l[i] <= r[i]){
            dp[i] = sub(sumdp[r[i] - 1], (l[i] == 1 ? 0 : sumdp[l[i] - 2]));
            if (r[i] == i and s[0][i] == '0'){
                dp[i] = add(dp[i], dp[i - 1]);
            }
        }
        sumdp[i] = add(sumdp[i - 1], (i == isz(s[0]) - 1 or s[0][i + 1] != '0' ? dp[i] : 0));
    }
    cout << dp[isz(s[0]) - 1] << endl;
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