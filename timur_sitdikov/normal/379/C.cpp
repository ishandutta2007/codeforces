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

const int MAXN = 300005;

pair<int, int> pp[MAXN];
int ans[MAXN];

void solve(){
    int n, i, cur;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &pp[i].first);
        pp[i].second = i;
    }
    sort(pp, pp + n);
    cur = -1;
    for(i = 0; i < n; i++){
        cur++;
        if (cur < pp[i].first){
            cur = pp[i].first;
        }
        ans[pp[i].second] = cur;
    }
    for(i = 0; i < n; i++){
        printf("%d ", ans[i]);
    }
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