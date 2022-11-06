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

int badi[MAXN], badj[MAXN];

void solve(){
    int n, m, i, i0, j0;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++){
        scanf("%d%d", &j0, &i0);
        badi[i0] = 1;
        badj[j0] = 1;
    }
    int ans = 0;
    for(i = 2; i < n; i++){
        if (i + i == n + 1){
            if (!badi[i] || !badj[i]){
                ans++;
            }
            continue;
        }
        if (!badi[i]){
            ans++;
        }
        if (!badj[i]){
            ans++;
        }
    }
    printf("%d", ans);
}

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    t = 1;
    while(t){
        t--;
        solve();
    }
}