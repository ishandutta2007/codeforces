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

const int maxn = 105, INF = 1e+9;

int v[maxn], cost[maxn];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, i, j, l, r, c, t, ans;
    cin >> n >> m;
    for(i = 1; i <= n; i++){
        v[i] = INF;
    }
    for(j = 0; j < m; j++){
        cin >> l >> r >> t >> c;
        for(i = l; i <= r; i++){
            if (v[i] > t){
                v[i] = t;
                cost[i] = c;
            }
        }
    }
    ans = 0;
    for(i = 1; i <= n; i++){
        if (cost[i] != INF){
            ans += cost[i];
        }
    }
    cout << ans;
}