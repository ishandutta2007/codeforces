//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int mod = (int)1e9 + 7;

const int N = 1003;

inline void iadd(int& x, int y){
    x += y;
    x -= x >= mod ? mod : 0;
}

inline int add(int x, int y){
    iadd(x, y);
    return x;
}

int dp[N][N][2][2];
int dp2[N][N];
int n, k;

void solve(){
    cin >> n >> k;
    dp2[1][0] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            iadd(dp[i + 1][j][0][0], dp2[i][j] * 1ll * (i - j - 1) % mod);
            iadd(dp[i + 1][j + 2][1][1], dp2[i][j]);
            if(j)
                iadd(dp[i + 1][j - 1][0][0], dp2[i][j] * 1ll * j % mod);
            iadd(dp2[i + 1][j], dp2[i][j]);
            for(int f1 = 0; f1 < 2; f1++){
                for(int f2 = 0; f2 < 2; f2++){
                    if(!dp[i][j][f1][f2])
                        continue;
                    int pure = j - f1 - f2;
                    int pure2 = i - j - (1 - f1) - (1 - f2);
                    if(pure < 0 || pure2 < 0)
                        continue;
                    iadd(dp2[i + 1][j], dp[i][j][f1][f2]);
                    iadd(dp[i + 1][j][0][0], dp[i][j][f1][f2] * 1ll * pure2 % mod);
                    if(j)
                        iadd(dp[i + 1][j - 1][0][0], dp[i][j][f1][f2] * 1ll * pure % mod);
                    if(f1)
                        iadd(dp[i + 1][j][0][1], dp[i][j][f1][f2]);
                    else
                        iadd(dp[i + 1][j + 1][0][1], dp[i][j][f1][f2]);
                    if(f2)
                        iadd(dp[i + 1][j][1][0], dp[i][j][f1][f2]);
                    else
                        iadd(dp[i + 1][j + 1][1][0], dp[i][j][f1][f2]);
                }
            }
        }
    }
    cout << add(add(add(dp[n][k][0][0], dp[n][k][0][1]), add(dp[n][k][1][0], dp[n][k][1][1])), dp2[n][k]) << endl;
}

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while(T--)
        solve();
    return 0;
}