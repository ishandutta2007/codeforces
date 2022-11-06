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

const int maxn = 100000, d = 100;
char col[d * maxn], good[d * maxn];
int a[maxn], p[maxn], top;

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x, i, j, ans;
    cin >> n >> x;
    if (x == 2){
        printf("0");
        return 0;
    }
    for(i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] == 1){
            printf("1");
            return 0;
        }
        if (a[i] < d * maxn)
            good[a[i]] = 1;
    }
    if (x >= d * maxn){
        printf("-1");
        return 0;
    }
    for(i = 2; i * i < d * maxn; i++){
        if (!col[i]){
            for(j = i * i; j < d * maxn; j += i)
                col[j] = 1;
        }
    }
    ans = 0;
    for(i = 2; i < x; i++){
        if (!col[i]){
            if (!good[i]){
                printf("-1");
                return 0;
            }
            ans++;
        }
    }
    printf("%d", ans);
}