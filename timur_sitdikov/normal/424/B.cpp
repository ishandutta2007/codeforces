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

const int MAXN = 1005;
pair<int, int> pp[MAXN];

void solve(){
    int i, n, x, y, s;
    cin >> n >> s;
    for(i = 0; i < n; i++){
        cin >> x >> y >> pp[i].second;
        pp[i].first = x * x + y * y;
    }
    sort(pp, pp + n);
    for(i = 0; i < n; i++){
        s += pp[i].second;
        if (s >= 1000000){
            printf("%.12lf", sqrt(pp[i].first + 0.));
            return;
        }
    }
    printf("-1");
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