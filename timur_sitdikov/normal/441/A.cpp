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
#define pii pair<int, int>
#define ll long long

#define FILE "file"

void solve(){
    int n, m, v, i, j, a;
    scanf("%d%d", &n, &v);
    vector<int> ans;
    for(i = 0; i < n; i++){
        scanf("%d", &m);
        int fl = 0;
        for(j = 0; j < m; j++){
            scanf("%d", &a);
            if (a < v){
                fl = 1;
            }
        }
        if (fl){
            ans.pb(i + 1);
        }
    }
    printf("%d\n", ans.size());
    for(i = 0; i < (int)ans.size(); i++){
        printf("%d ", ans[i]);
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