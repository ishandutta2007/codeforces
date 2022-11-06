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
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

const int MAXN = 10005;
int ans[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, k, i, ind, j;
    cin >> n >> k;
    for(j = 0; j < k; j++){
        if ((1 << j) > n){
            for(i = 0; i < n; i++){
                printf("%d ", n);
            }
            putchar('\n');
            continue;
        }
        for(i = 0; i < (1 << j); i++){
            ans[n - i] = n;
        }
        for(i = (1 << j); i < min(n, (1 << (j + 1))); i++){
            ans[n - i] = n - i + (1 << j);
        }
        for(i = (1 << (j + 1)); i < n; i++){
            ans[n - i] = n - (1 << j);
        }
        for(i = 1; i <= n; i++){
            printf("%d ", ans[i]);
        }
        putchar('\n');
    }
}