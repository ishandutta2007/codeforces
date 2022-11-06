#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>

#define file "cycle"

double pow_mod(double a, int n){
    double ans = 1.;
    for(; n; n >>= 1){
        if (n & 1){
            ans *= a;
        }
        a *= a;
    }
    return ans;
}

void solve(){
    int m, n, i;
    double ans, tmp, p, p1;
    cin >> m >> n;
    ans = 0., p = 0.;
    for(i = m; i >= 1; i--){
        tmp = pow_mod((i - 1.) / (m + 0.), n);
        p1 = 1. - p - tmp;
        ans += p1 * i;
        p += p1;
    }
    printf("%.12lf\n", ans);
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    while(t--){
        solve();    
    }
}