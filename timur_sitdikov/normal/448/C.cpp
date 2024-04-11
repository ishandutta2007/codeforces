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

const int MAXN = 5005;

int v[MAXN];

ll rec_sol(int l, int r, ll level){
    if (l > r){
        return 0;
    }
    ll ans = r - l + 1;
    int mn = v[l], mini = l;
    for(int i = l + 1; i <= r; i++){
        if (v[i] < mn){
            mn = v[i];
            mini = i;
        }
    }
    ll v1 = rec_sol(l, mini - 1, mn);
    ll v2 = rec_sol(mini + 1, r, mn);
    ll v3 = v1 + v2 + mn - level;
    return min(ans, v3);
}

void solve(){
    int n, i;
    ll ans;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    ans = rec_sol(0, n - 1, 0ll);
    cout << ans << endl;
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