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

const int MAXN = 200005;

int m[MAXN];

map<int, int> cnt;

void solve(){
    int n, i, j, k, lim;
    scanf("%d%d%d", &n, &lim, &k);
    if (k == 0){
        printf("1\n");
        return;
    }
    for(i = 0; i < n; i++){
        scanf("%d", &m[i]);
    }
    for(i = 0; i < k - 1; i++){
        cnt[-m[i]]++;
    }
    int ans = 0;
    for(i = k - 1; i < n; i++){
        cnt[-m[i]]++;
        if (cnt.empty() || -cnt.begin()->first <= lim){
            ans++;
        }
        cnt[-m[i - k + 1]]--;
        if (cnt[-m[i - k + 1]] == 0){
            cnt.erase(-m[i - k + 1]);
        }
    }
    printf("%d\n", ans);
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