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

const int MAXN = 3005;

vector<int> g1[MAXN], g2[MAXN];

void solve(){
    int n, i, a, b, v, v1, ans = 0;
    scanf("%d%d", &n, &v);
    for(i = 0; i < n; i++){
        scanf("%d%d", &a, &b);
        g1[a].pb(b);
    }
    ans = 0;
    for(i = 1; i <= 3001; i++){
        v1 = v;
        for(int j = 0; j < (int)g2[i].size(); j++){
            int tmp = min(g2[i][j], v1);
            v1 -= tmp;
            ans += tmp;
        }
        for(int j = 0; j < (int)g1[i].size(); j++){
            int tmp = min(g1[i][j], v1);
            ans += tmp;
            v1 -= tmp;
            if (g1[i][j] > tmp){
                g2[i + 1].pb(g1[i][j] - tmp);
            }
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