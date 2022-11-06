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
    int n, m, k, i, j, cur, cnt;
    cin >> n >> m >> k;
    cnt = 0;
    for(i = 1, j = 1, cur = 0; i <= n && j <= m; cnt++){
        if (cur == 0){
            cur = (k == 1 ? n * m - cnt : 2);
            k--;
            printf("%d ", cur);
        }
        printf("%d %d ", i, j);
        cur--;
        if (cur == 0){
            putchar('\n');
        }
        if (i & 1){
            j++;
            if (j == m + 1){
                j = m;
                i++;
            }
        } else {
            j--;
            if (j == 0){
                j = 1;
                i++;
            }
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