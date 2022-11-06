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

ll calc(ll n, ll m, ll x, ll y){
    return (n / (x + 1)) * (m / (y + 1));
}
void solve(){
    ll n, m, k, lim = 3e6;
    cin >> n >> m >> k;
    if (k > n + m - 2){
        printf("-1\n");
        return;
    }
    ll ans = -1;
    ll s, i, j;
    s = max(0ll, k - (m - 1));
    for(i = s; i <= s + lim; i++){
        j = k - i;
        if (i < 0 || i > k || j < 0 || j > k){
            continue;
        }
        ans = max(ans, calc(n, m, i, j));
    }
    s = max(0ll, k - (n - 1));
    for(j = s; j <= s + lim; j++){
        i = k - j;
        if (i < 0 || i > k || j < 0 || j > k){
            continue;
        }
        ans = max(ans, calc(n, m, i, j));
    }
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