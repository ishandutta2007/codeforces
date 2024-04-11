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

const int MAXN = 1005;

int cnt[MAXN], nxt[MAXN], prv[MAXN], dp[MAXN];

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int i, j, n, x, top = 0, cur, f, dd;
    cin >> n >> x;
    for(i = 1; i <= n; i++){
        cin >> nxt[i];
        prv[nxt[i]] = i;
    }
    for(i = 1; i <= n; i++){
        if (nxt[i])
            continue;
        cur = 0;
        f = 0;
        for(j = i; j; j = prv[j]){
            if (j == x){
                f = 1;
                dd = cur + 1;
            }
            cur++;
        }
        if (!f){
            cnt[top++] = cur;
        }
    }
    dp[0] = 1;
    for(i = 0; i < top; i++){
        for(j = n; j >= 0; j--){
            if (dp[j] && j + cnt[i] <= n){
                dp[j + cnt[i]] = 1;
            }
        }
    }
    for(i = 0; i <= n; i++){
        if (dp[i]){
            printf("%d\n", i + dd);
        }
    }

}