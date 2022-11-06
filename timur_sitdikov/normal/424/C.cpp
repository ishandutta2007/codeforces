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
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

#define FILE "file"

const int MAXN = 1000005;

int xxor[MAXN], val[MAXN];

void solve(){
    int n, i, j, ans = 0;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &val[i]);
        ans ^= val[i];
        xxor[i] = xxor[i - 1] ^ i;
    }
    for(i = 1; i <= n; i++){
        j = n / i;
        if (j & 1){
            ans ^= xxor[i - 1];
        }
        j = n % i;
        ans ^= xxor[j];
    }
    printf("%d", ans);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //assert(freopen(FILE ".in", "r", stdin));assert(freopen(FILE ".out", "w", stdout));
    int t = 1;
    while(t){
        t--;
        solve();
    }
}