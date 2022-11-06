#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

const int maxn = 205;
int dp[maxn][maxn][maxn];
const int INF = 1 << 29;
int g[maxn][maxn];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i, j, k, l, lim, n, m, c, ans;
    string s;
    string a, b;
    cin >> s >> lim >> m;
    for(i = 0; i < m; i++){
        cin >> a >> b >> c;
        g[a[0]][b[0]] = c;
    }
    n = s.length();
    for(i = 0; i < n; i++){
        for(j = 0; j <= lim; j++){
            for(k = 'a'; k <= 'z'; k++){
                dp[i][j][k] = -INF;
            }
        }
    }
    for(k = 'a'; k <= 'z'; k++){
        int ind = (k == s[0]? 0: 1);
        dp[0][ind][k] = 0;
    }
    for(i = 1; i < n; i++){
        for(j = 0; j <= lim; j++){
            if (j){
                for(k = 'a'; k <= 'z'; k++){
                    if (k == s[i])
                        continue;
                    for(l = 'a'; l <= 'z'; l++){
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][l] + g[l][k]);
                    }
                }
            }
            for(l = 'a'; l <= 'z'; l++){
                dp[i][j][s[i]] = max(dp[i][j][s[i]], dp[i - 1][j][l] + g[l][s[i]]);
            }
        }
    }
    ans = dp[n - 1][lim]['a'];
    for(j = 0; j <= lim; j++){
        for(k = 'a'; k <= 'z'; k++){
            ans = max(ans, dp[n - 1][j][k]);
        }
    }
    cout << ans;
}