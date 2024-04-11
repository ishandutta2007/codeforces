#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i: a)
#define bend(a) a.begin(), a.end()
#define isz(a) (int)a.size()

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef vector <vi > vvi;
typedef vector <pii > vpii;

const int N = 5e2 + 5;

int n;
int a[N];
int dp[N][N];
int dp2[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
        dp[i][i] = a[i];
    }
    ForE(len, 2, n){
        ForE(i, 1, n - len + 1){
            int j = i + len - 1;
            dp[i][j] = -1;
            ForE(k, i, j - 1){
                if (dp[i][k] != -1 && dp[i][k] == dp[k + 1][j]){
                    dp[i][j] = dp[i][k] + 1;
                    break;
                }
            }
        }
    }
    ForE(i, 1, n){
        dp2[i] = N;
        ForE(j, 1, i){
            if (dp[j][i] != -1){
                dp2[i] = min(dp2[i], dp2[j - 1] + 1);
            }
        }
    }
    cout << dp2[n];
}