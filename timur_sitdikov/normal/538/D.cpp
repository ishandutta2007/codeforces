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

const int MAXN = 105;

char c[MAXN][MAXN];
int b[MAXN][MAXN], ans[MAXN][MAXN];

int is_good(int n, int i, int j){
    return i >= 0 && j >= 0 && i < n && j < n;
}

void solve(){
    int n, i, j, k, l;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s", &c[i][0]);
    }
    for(i = -n + 1; i < n; i++){
        for(j = -n + 1; j < n; j++){
            int fl0 = 0;
            for(k = 0; k < n; k++){
                for(l = 0; l < n; l++){
                    if (!is_good(n, k + i, l + j)){
                        continue;
                    }
                    if (c[k][l] == 'o' && c[k + i][l + j] == '.'){
                        fl0 = 1;
                    }
                }
            }
            if (fl0){
                continue;
            }
            ans[i + n - 1][j + n - 1] = 1;
            for(k = 0; k < n; k++){
                for(l = 0; l < n; l++){
                    if (!is_good(n, k + i, l + j)){
                        continue;
                    }
                    if (c[k][l] == 'o' && c[k + i][l + j] == 'x'){
                        b[k + i][l + j] = 1;
                    }
                }
            }

        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if (c[i][j] == 'x' && !b[i][j]){
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
    for(i = 0; i < 2 * n - 1; i++){
        for(j = 0; j < 2 * n - 1; j++){
            if (i == n - 1 && j == n - 1){
                putchar('o');
            } else if (ans[i][j]){
                putchar('x');
            } else {
                putchar('.');
            }
        }
        putchar('\n');
    }
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