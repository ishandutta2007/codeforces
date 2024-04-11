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

const int maxn = 100005;
int c[maxn];
long long v[maxn];
long long dp[maxn], dp_col[maxn], init[maxn];
pair<int, long long> all_mx[2];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i, j, k, q;
    long long a, b, mxa, mxb, ans;
    scanf("%d %d", &n, &q);
    for(i = 1; i <= n; i++){
        scanf("%I64d", &v[i]);
    }
    for(i = 1; i <= n; i++){
        scanf("%d", &c[i]);
    }
    for(j = 0; j < q; j++){
        scanf("%I64d %I64d", &a, &b);
        for(i = 1; i <= n; i++){
            dp[i] = 0;
            init[i] = 0;
            dp_col[i] = 0;
        }
        all_mx[0] = all_mx[1] = mp(0, 0);
        for(i = 1; i <= n; i++){
            mxa = dp_col[c[i]];
            if (all_mx[0].first == c[i])
                mxb = all_mx[1].second;
            else
                mxb = all_mx[0].second;
            if (!init[c[i]]){
                dp[i] = mxb + b * v[i];
            }
            else{
                dp[i] = max(mxa + a * v[i], mxb + b * v[i]);
            }
            if (dp_col[c[i]] < dp[i] || !init[c[i]]){
                init[c[i]] = 1;
                dp_col[c[i]] = dp[i];
                for(k = 0; k < 2; k++){
                    if (all_mx[k].first == c[i]){
                        all_mx[k].second = max(all_mx[k].second, dp_col[c[i]]);
                        break;
                    }
                }
                if (k < 2){
                    if (all_mx[0].second < all_mx[1].second){
                        swap(all_mx[0], all_mx[1]);
                    }
                }
                else{
                    if (all_mx[0].second <= dp_col[c[i]]){
                        all_mx[1] = all_mx[0];
                        all_mx[0] = mp(c[i], dp_col[c[i]]);
                    }
                    else if (all_mx[1].second < dp_col[c[i]]){
                        all_mx[1] = mp(c[i], dp_col[c[i]]);
                    }
                }
            }
        }
        ans = 0;
        for(i = 1; i <= n; i++){
            ans = max(ans, dp[i]);
        }
        printf("%I64d\n", ans);
    }
}