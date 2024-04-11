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

void solve(){
    long long cur, ans;
    int i, n, a;
    scanf("%d", &n);
    cur = ans = 0;
    for(i =0; i < n; i++){
        scanf("%d", &a);
        cur += a;
        if (a == 0){
            ans += cur;
        }
    }
    printf("%I64d", ans);
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