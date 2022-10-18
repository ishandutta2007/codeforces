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

const int N = 4e2 + 5;

int n, m;
string s, t;
int dp[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    cin >> s; n = s.length(); s = ' ' + s;
    cin >> t; m = t.length(); t = ' ' + t;
    bool ck = 0;
    ForE(idx, 1, m){
        ForE(i, 0, n){
            ForE(j, 0, idx){
                dp[i][j] = -1;
            }
        }
        dp[0][0] = idx;
        ForE(i, 1, n){
            ForE(j, 0, idx){
                dp[i][j] = dp[i - 1][j];
                if (j && s[i] == t[j]){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                }
                if (dp[i - 1][j] != m && dp[i - 1][j] != -1 && s[i] == t[dp[i - 1][j] + 1]){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
                }
            }
        }
        if (dp[n][idx] == m){
            ck = 1;
            break;
        }
    }
    if (ck){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
}