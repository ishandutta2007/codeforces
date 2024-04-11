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

const int MAXN = 250005, MAXC = 55;
long long dp[MAXN];
long long mx_in[MAXC], mx_l[MAXC], mx_r[MAXC], sum[MAXC];
long long v[5005];
const long long INF = 1e12;

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, i, k, cnt, ind;
    long long mx = -INF, cur;
    scanf("%d %d", &m, &n);
    for(k = 0; k < m; k++){
        scanf("%d", &cnt);
        for(i = 0; i < cnt; i++)
            scanf("%I64d", &v[i]);
        mx_l[k] = v[0];
        cur = mx_l[k];
        for(i = 1; i < cnt; i++){
            cur += v[i];
            mx_l[k] = max(mx_l[k], cur);
        }
        mx_r[k] = v[cnt - 1];
        cur = mx_r[k];
        for(i = cnt - 2; i >= 0; i--){
            cur += v[i];
            mx_r[k] = max(mx_r[k], cur);
        }
        mx_in[k] = mx_l[k];
        cur = 0;
        for(i = 0; i < cnt; i++){
            cur += v[i];
            mx_in[k] = max(mx_in[k], cur);
            if (cur < 0)
                cur = 0;
        }
        for(i = 0; i < cnt; i++)
            sum[k] += v[i];
    }
    for(i = 1; i <= n; i++){
        scanf("%d", &ind);
        ind--;
        //dp[i] = -INF;
        dp[i] = max(dp[i - 1] + sum[ind], mx_r[ind]);
        mx = max(mx, dp[i - 1] + mx_l[ind]);
        mx = max(mx, dp[i]);
        mx = max(mx, mx_in[ind]);
    }
    printf("%I64d", mx);
}