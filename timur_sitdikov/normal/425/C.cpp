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
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

#define FILE "file"

const int MAXN = 100005, MAXLEN = 305;

int a[MAXN], b[MAXN];

vector<int> pos[MAXN];

int dp[2][MAXN];

void solve(){
    int n, m, i, j, k, s, e;
    scanf("%d%d%d%d", &n, &m, &s, &e);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i + 1]);
    }
    for(i = 0; i < m; i++){
        scanf("%d", &b[i]);
        pos[b[i]].pb(i + 1);
    }
    for(i = 0; i < MAXLEN; i++){
        dp[0][i] = -1;
    }
    dp[0][0] = 0;
    int ans = 0;
    int lim = s / e;
    int tmp;
    int offset;
    for(j = 1; j <= n; j++){
        tmp = a[j];
        int sz = pos[tmp].size();
        int ind = 1 - (j & 1);
        for(i = 0; i <= lim; i++){
            dp[ind ^ 1][i] = dp[ind][i];
        }
        if (sz == 0){
            continue;
        }
        for(i = 0; i < lim; i++){
            if (dp[ind][i] != -1){
                if (pos[tmp][sz - 1] > dp[ind][i]){
                    offset = *upper_bound(pos[tmp].begin(), pos[tmp].end(), dp[ind][i]);
                    if (dp[ind ^ 1][i + 1] == -1 || offset < dp[ind ^ 1][i + 1]){
                        dp[ind ^ 1][i + 1] = offset;
                        if (j + offset + (i + 1) * e <= s){
                            ans = max(ans, i + 1);
                        }
                    }
                }
            }
        }
        /*for(i = 0; i <= lim; i++){
            printf("%d %d\n", i, dp[ind ^ 1][i]);
        }
        putchar('\n');*/
    }
    printf("%d\n", ans);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //assert(freopen(FILE ".in", "r", stdin));assert(freopen(FILE ".out", "w", stdout));
    int t = 1;
    while(t){
        t--;
        solve();
    }
}