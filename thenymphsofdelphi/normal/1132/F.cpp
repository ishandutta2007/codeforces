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

const int N = 5e2 + 5;

int n;
string s;
int dp[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s; s = ' ' + s;
    ForE(len, 1, n){
        ForE(i, 1, n - len + 1){
            int j = i + len - 1;
            if (len == 1){
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = 1 + dp[i + 1][j];
            ForE(k, i + 1, j){
                if (s[k] == s[i]){
                    dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                }
            }
        }
    }
    cout << dp[1][n];
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