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

const int MAXN = 105;

char c[MAXN][MAXN];

int fr_r[MAXN], fr_c[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%s", &c[i][1]);
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if (c[i][j] == '.'){
                fr_r[i] = j;
            }
        }
        for(j = 1; j <= n; j++){
            if (c[j][i] == '.'){
                fr_c[i] = j;
            }
        }
    }
    int f = 0;
    for(i = 1; i <= n; i++){
        if (fr_r[i] == 0){
            f = 1;
            break;
        }
    }
    if (f == 0){
        for(i = 1; i <= n; i++){
            printf("%d %d\n", i, fr_r[i]);
        }
        return 0;
    }
    f = 0;
    for(i = 1; i <= n; i++){
        if (fr_c[i] == 0){
            f = 1;
            break;
        }
    }
    if (f == 0){
        for(i = 1; i <= n; i++){
            printf("%d %d\n", fr_c[i], i);
        }
        return 0;
    }
    printf("-1");
}