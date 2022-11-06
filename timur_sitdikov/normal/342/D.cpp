#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

const int MAXN = 10055;
const int MOD = 1000000007;

char c[3][MAXN], c1[3][MAXN];

int dp[8][MAXN], ans;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, j, k, mask, mask1, mask2, x, y, bit_cnt, sgn;
    scanf("%d%s%s%s", &n, &c[0][1], &c[1][1], &c[2][1]);
    for(i = 0; i < 3; i++){
        for(j = 1; j <= n; j++){
            if (c[i][j] == 'O'){
                x = j;
                y = i;
                c[i][j] = 'X';
            }
        }
    }
    for(j = 1; j < 8; j++){
        for(i = 1; i <= n; i++){
            c1[0][i] = c1[1][i] = c1[2][i] = '.';
        }
        bit_cnt = 0;
        if (j & 1){
            if (x <= 2 || c[y][x - 1] == 'X' || c[y][x - 2] == 'X'){
                continue;
            }
            c1[y][x - 1] = c1[y][x - 2] = 'X';
            bit_cnt++;
        }
        if (j & 2){
            if (x >= n - 1 || c[y][x + 1] == 'X' || c[y][x + 2] == 'X'){
                continue;
            }
            c1[y][x + 1] = c1[y][x + 2] = 'X';
            bit_cnt++;
        }
        if (j & 4){
            if (y == 1)
                continue;
            if (y == 0) {
                if (c[y + 1][x] == 'X' || c[y + 2][x] == 'X'){
                    continue;
                }
                else {
                    c1[y + 1][x] = c1[y + 2][x] = 'X';
                }
            }
            if (y == 2) {
                if (c[y - 1][x] == 'X' || c[y - 2][x] == 'X'){
                    continue;
                }
                else {
                    c1[y - 1][x] = c1[y - 2][x] = 'X';
                }
            }
            bit_cnt++;
        }
        for(i = 1; i <= n; i++){
            for(k = 0; k < 3; k++){
                if (c1[k][i] == '.'){
                    c1[k][i] = c[k][i];
                }
            }
        }
        for(i = 0; i <= n + 1; i++){
            for(mask = 0; mask < 8; mask++){
                dp[mask][i] = 0;
            }
        }
        mask = 0;
        for(k = 0; k < 3; k++){
            if (c1[k][1] == 'X'){
                mask |= (1 << k);
            }
        }
        dp[mask][1] = 1;
        for(i = 1; i <= n; i++){
            for(mask = 0; mask < 8; mask++){
                if (dp[mask][i] == 0)
                    continue;
                if ((mask & 3) == 0){
                    dp[mask | 3][i] = (dp[mask | 3][i] + dp[mask][i]) % MOD;
                }
                if ((mask & 6) == 0){
                    dp[mask | 6][i] = (dp[mask | 6][i] + dp[mask][i]) % MOD;
                }
                mask1 = 0;
                for(k = 0; k < 3; k++){
                    if (c1[k][i + 1] == 'X'){
                        mask1 |= (1 << k);
                    }
                }
                if ((7 ^ mask) & mask1){
                    continue;
                }
                mask2 = (7 ^ mask) | mask1;
                dp[mask2][i + 1] = (dp[mask2][i + 1] + dp[mask][i]) % MOD;
            }
        }
        if (bit_cnt == 2){
            ans = (ans + MOD - dp[0][n + 1]) % MOD;
        }
        else {
            ans = (ans + dp[0][n + 1]) % MOD;
        }
    }
    printf("%d", ans);
}