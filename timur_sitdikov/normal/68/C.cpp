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
#define xx first
#define yy second

const int maxn = 10;
int mm[maxn][maxn], cnt[maxn], ans = 1000, ans_cost = 1000, n;
int a[maxn][maxn], l[maxn][maxn], h[maxn][maxn], g[maxn][maxn];

void calc_cost(){
    int i, j, cost = 0, sum = 0;
    for(i = 1; i < n; i++)
        sum += g[i][n];
    if (sum > ans)
        return;
    for(i = 1; i < n; i++){
        for(j = i + 1; j <= n; j++){
            if (g[i][j]){
                cost += a[i][j] + g[i][j] * g[i][j];
            }
        }
    }
    if (sum < ans || cost > ans_cost){
        ans = sum;
        ans_cost = cost;
    }
}

int gen_next(int n, int level){
    int i, tmp;
    for(i = 0; i < n - 1 && !mm[level][i]; i++);
    if (i == n - 1)
        return 1;
    mm[level][i + 1]++;
    tmp = mm[level][i] - 1;
    mm[level][i] = 0;
    mm[level][0] = tmp;
    return 0;
}

void rec_sol(int level){
    if (level == n){
        calc_cost();
        return;
    }
    int i, sz = n - level, f, level2;
    mm[level][0] = cnt[level];
    for(i = 1; i < sz; i++)
        mm[level][i] = 0;
    while(1){
        f = 0;
        for(i = 0; i < sz; i++){
            level2 = level + i + 1;
            g[level][level2] += mm[level][i];
            cnt[level2] += mm[level][i];
            if (g[level][level2] < l[level][level2] || g[level][level2] > h[level][level2])
                f = 1;
        }
        if (!f)
            rec_sol(level + 1);
        for(i = 0; i < sz; i++){
            level2 = level + i + 1;
            g[level][level2] -= mm[level][i];
            cnt[level2] -= mm[level][i];
        }
        if (gen_next(sz, level))
            break;
    }
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i, j, s, f, ll, hh, aa;
    cin >> n;
    for(i = 0; i < n * (n - 1) / 2; i++){
        cin >> s >> f >> ll >> hh >> aa;
        a[s][f] = aa;
        l[s][f] = ll;
        h[s][f] = hh;
    }
    for(i = 0; i <= 25; i++){
        for(j = 1; j <= n; j++)
            cnt[j] = 0;
        cnt[1] = i;
        rec_sol(1);
    }   
    if (ans == 1000){
        cout << "-1 -1";
        return 0;
    }
    cout << ans << " " << ans_cost;
}