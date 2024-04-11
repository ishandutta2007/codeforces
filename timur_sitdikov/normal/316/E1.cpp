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

const long long mod = 1000000000;

const int MAXN = 105;
long long f[MAXN];

long long a[MAXN];

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, i, j, k, t, l, r;
    long long v, ans;
    scanf("%d %d", &n ,&m);
    f[0] = f[1] = 1;
    for(i = 2; i <= n; i++){
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
    for(i = 0; i < n; i++){
        scanf("%I64d", &a[i]);
    }
    for(i = 0; i < m; i++){
        scanf("%d", &t);
        if (t == 1){
            scanf("%d %I64d", &j, &v);
            j--;
            a[j] = v;
        }
        else if (t == 2){
            scanf("%d %d", &l, &r);
            l--;
            r--;
            ans = 0;
            for(j = 0; j <= r - l; j++){
                ans = (ans + f[j] * a[j + l]) % mod;
            }
            printf("%I64d\n", ans);
        }
        else{
            scanf("%d %d %I64d", &l, &r, &v);
            l--;
            r--;
            for(j = l; j <= r; j++){
                a[j] = (a[j] + v) % mod;
            }
        }
    }
}