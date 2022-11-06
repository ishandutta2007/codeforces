#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>

#define file "cycle"

const int MAXV = 59, MAXN = 105, MAXP = 16, INF = 1e9;

int mask[MAXV];
int pp[MAXP] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int v[MAXN];
int dp[MAXN][1 << MAXP], prv_num[MAXN][1 << MAXP], prv_mask[MAXN][1 << MAXP];

void solve(){
    int i, j, k, n;
    for(i = 1; i < MAXV; i++){
        for(j = 0; j < MAXP; j++){
            if (i % pp[j] == 0){
                mask[i] |= (1 << j);
            }
        }
    }
    /*printf("1\n");
    return;*/
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> v[i];
    }
    reverse(v + 1, v + n + 1);
    /*printf("#\n");
    return;*/
    for(i = 0; i <= n; i++){
        for(j = 0; j < (1 << MAXP); j++){
            dp[i][j] = INF;
        }
    }
    /*printf("*\n");
    return;*/
    dp[0][0] = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < (1 << MAXP); j++){
            for(k = 1; k < MAXV; k++){
                if (!(j & mask[k]) && dp[i + 1][j | mask[k]] > dp[i][j] + abs(k - v[i + 1])){
                    dp[i + 1][j | mask[k]] = dp[i][j] + abs(k - v[i + 1]);
                    prv_num[i + 1][j | mask[k]] = k;
                    prv_mask[i + 1][j | mask[k]] = j;
                }
            }
        }
    }
    int ans = INF, mini = -1;
    for(i = 0; i < (1 << MAXP); i++){
        if (dp[n][i] < ans){
            ans = dp[n][i];
            mini = i;
        }
    }
    /*printf("%d %d\n", ans, mini);
    return;*/
    for(i = n; i; i--){
        cout << prv_num[i][mini] << " ";
        mini = prv_mask[i][mini];
    }
    cout << endl;
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    while(t--){
        /*printf("2\n");
        return 0;*/
        solve();    
    }
}