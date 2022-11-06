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

const int MAXN = 500005;

int v[MAXN];

void solve(){
    int n, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    sort(v, v + n);
    int ans = n;
    i = n - 1;
    j = (n - 2) / 2;
    for(; j >= 0; j--){
        if (v[j] * 2 <= v[i]){
            ans--;
            i--;
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