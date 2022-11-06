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

const int MAXN = 2e5 + 5, INF = 1e9;

pii pp[MAXN];

void solve(){
    int n, k, i, j, a;
    scanf("%d%d", &n, &k);
    int top = 0;
    for(i = 0; i < n; i++){
        scanf("%d", &a);
        for(j = 1; j <= k; j++){
            pp[top++] = mp(a * j, j);
        }
    }
    sort(pp, pp + top);
    pp[top++] = mp(INF, INF);
    int q, x, ans;
    scanf("%d", &q);
    for(; q; q--){
        scanf("%d", &x);
        ans = INF;
        pii tmp = *lower_bound(pp, pp + top, mp(x, 0));
        if (tmp.first == x){
            ans = tmp.second;
        }
        for(i = 0; i < top; i++){
            if (pp[i].first > x){
                break;
            }
            tmp = *lower_bound(pp, pp + top, mp(x - pp[i].first, 0));
            if (tmp.first == x - pp[i].first){
                ans = min(ans, pp[i].second + tmp.second);
            }
        }
        if (ans > k){
            ans = -1;
        }
        printf("%d\n", ans);
    }
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