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

void solve(){
    int n, k;
    cin >> n >> k;
    if (2 * k > n - 1){
        printf("-1");
        return;
    }
    printf("%d\n", k * n);
    for(int i = 0; i < n; i++){
        for(int j = i + 1, l = 0; l < k; l++, j++){
            printf("%d %d\n", i + 1, (j % n) + 1);
        }
    }
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