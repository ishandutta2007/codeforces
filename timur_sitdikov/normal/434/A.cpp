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

const int MAXN = 300005;

int v[MAXN], vv[MAXN];

vector<int> c[MAXN];

void solve(){
    int n, m, i, j, top;
    ll ans, sum, cur, v1, v2;
    scanf("%d%d", &n, &m);
    sum = 0;
    for(i = 0; i < m; i++){
        scanf("%d", &v[i]);
        c[v[i]].pb(i);
        if (i){
            sum += abs(v[i] - v[i - 1]);
        }
    }
    ans = sum;
    for(i = 1; i <= n; i++){
        if (c[i].empty()){
            continue;
        }
        top = 0;
        v1 = 0;
        for(j = 0; j < (int)c[i].size(); j++){
            int ind = c[i][j];
            if (ind > 0){
                if (v[ind - 1] != i){
                    vv[top++] = v[ind - 1];
                    v1 += abs(v[ind - 1] - i);
                }
            }
            if (ind < m - 1){
                if (v[ind + 1] != i){
                    vv[top++] = v[ind + 1];
                    v1 += abs(v[ind + 1] - i);
                }
            }
        }
        sort(vv, vv + top);
        int tmp = vv[top / 2];
        v2 = 0;
        for(j = 0; j < top; j++){
            v2 += abs(vv[j] - tmp);
        }
    //  cout << sum << " " << v1 << " " << v2 << endl;
        cur = sum - v1 + v2;
        ans = min(ans, cur);
    }
    cout << ans;
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