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

const int MAXN = 1005;

char c[MAXN][MAXN];
int sum[MAXN][MAXN], sum_g[MAXN][MAXN];
int n, m;

int get_sum(int i1, int j1, int i2, int j2){
    return sum[i2][j2] - sum[i2][j1 - 1] - sum[i1 - 1][j2] + sum[i1 - 1][j1 - 1];   
}

int check(int i1, int j1, int i2, int j2, int cnt){
    if (i2 > n || j2 > m){
        return 0;
    }
    if (get_sum(i1, j1, i2, j2) != (i2 - i1 + 1) * (j2 - j1 + 1)){
        return 0;
    }
    if (c[i1][j2 + 1] == 0 && c[i2 + 1][j1] == 0){
        if (cnt == sum[n][m]){
            return 1;
        }
        return 0;
    }
    if (c[i1][j2 + 1] == 1 && c[i2 + 1][j1] == 1){
        return 0;
    }
    if (c[i1][j2 + 1] == 1){
        return check(i1, j1 + 1, i2, j2 + 1, cnt + (i2 - i1 + 1));
    } else {
        return check(i1 + 1, j1, i2 + 1, j2, cnt + (j2 - j1 + 1));
    }
}

void solve(){
    int i, j, i0, j0, fl = 0;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++){
        scanf("%s", &c[i][1]);
        for(j = 1; j <= m; j++){
            if (c[i][j] == '.'){
                c[i][j] = 0;
            } else {
                if (!fl){
                    fl = 1;
                    i0 = i;
                    j0 = j;
                }
                c[i][j] = 1;
            }
            sum_g[i][j] = sum_g[i][j - 1] + c[i][j];
            sum[i][j] = sum[i - 1][j] + sum_g[i][j];
        }
    }
    int a, b;
    for(i = i0, a = 0; c[i][j0]; i++, a++);
    for(j = j0, b = 0; c[i0][j]; j++, b++);
    int s = -1;
    for(j = 1; j <= m; j++){
        if (check(i0, j0, i0 + a - 1, j0 + j - 1, a * j)){
            if (s == -1 || a * j < s){
                s = a * j;
            }
        }
    }
    for(i = 1; i <= n; i++){
        if (check(i0, j0, i0 + i - 1, j0 + b - 1, i * b)){
            if (s == -1 || i * b < s){
                s = i * b;
            }
        }
    }
    cout << s << endl;
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    while(t--){
        solve();    
    }
}