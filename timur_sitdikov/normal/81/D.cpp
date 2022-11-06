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
#include <list>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

pair<int, int> pp[1005];
int ans[1005], v[1005];

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, j, ost, m, a, tmp, lst;
    cin >> n >> m;
    for(i = 0; i < m; i++){
        cin >> a;
        pp[i] = mp(a, i + 1);
    }
    sort(pp, pp + m);
    reverse(pp, pp + m);
    ost = n;
    for(i = 0; i < m; i++){
        tmp = min(n / 2, ost);
        tmp = min(tmp, pp[i].first);
        v[i] = tmp;
        ost -= tmp;
    }
    if (ost > 0){
        cout << -1;
        return 0;
    }
    ans[0] = pp[0].second;
    v[0]--;
    lst = 0;
    int mx, maxj;
    for(i = 1; i < n; i++){
        mx = -1;
        for(j = 0; j < m; j++){
            if (v[j] > mx && j != lst){
                mx = v[j];
                maxj = j;
            }
        }
        ans[i] = pp[maxj].second;
        v[maxj]--;
        lst = maxj;
    }
    for(i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}