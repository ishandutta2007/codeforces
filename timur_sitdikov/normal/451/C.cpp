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

int is_good(ll x, ll a, ll b, ll c){
    return a >= 0 && a <= x && b >= 0 && b <= x && c >= 0 && c <= x;
}

void solve(){
    ll n, k, d1, d2, x, y, a, b;
    //cin >> n >> k >> d1 >> d2;
    scanf("%lld%lld%lld%lld", &n, &k, &d1, &d2);
    x = n / 3;
    if (3 * x != n){
        printf("no\n");
        return;
    }
    y = (k - d1 - d2) / 3;
    if (3 * y == k - d1 - d2 && is_good(x, y, y + d1, y + d2)){
        printf("yes\n");
        return;
    }
    y = (k - d1 + d2) / 3;
    if (3 * y == k - d1 + d2 && is_good(x, y, y + d1, y - d2)){
        printf("yes\n");
        return;
    }
    y = (k + d1 - d2) / 3;
    if (3 * y == k + d1 - d2 && is_good(x, y, y - d1, y + d2)){
        printf("yes\n");
        return;
    }
    y = (k + d1 + d2) / 3;
    if (3 * y == k + d1 + d2 && is_good(x, y, y - d1, y - d2)){
        printf("yes\n");
        return;
    }
    printf("no\n");
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--){
        solve();    
    }
}