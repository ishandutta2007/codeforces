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

vector<int> len;
const int INF = 1000000000;

int is_sign(char c){
    return c == '.' || c == '?' || c == '!';
}

int dp[10005][260];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char c[10005];
    int l, n, i, j, curlen, sz, ans;
    scanf("%d", &n);
    curlen = 0;
    while(scanf("%s", &c) == 1){
        l = strlen(c);
        curlen += l + 1;    
        if (is_sign(c[l - 1])){
            curlen--;
            if (curlen > n){
                printf("Impossible");
                return 0;
            }
            len.pb(curlen);
            curlen = 0;
        }
    }
    sz = len.size();
    for(i = 0; i < sz; i++){
        for(j = 0; j <= n; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][len[0]] = 0;
    for(i = 0; i < sz - 1; i++){
        for(j = 0; j <= n; j++){
            if (j + len[i + 1] + 1 <= n){
                dp[i + 1][j + len[i + 1] + 1] = min(dp[i + 1][j + len[i + 1] + 1], dp[i][j]);
            }
            dp[i + 1][len[i + 1]] = min(dp[i + 1][len[i + 1]], dp[i][j] + 1);
        }
    }
    ans = dp[sz - 1][0];
    for(i = 1; i <= n; i++)
        ans = min(ans, dp[sz - 1][i] + 1);
    cout << ans;
}