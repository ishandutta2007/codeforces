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

void solve(){
    int i, j;
    ll n, m, k, l, r, cnt, mid, v;
    cin >> n >> m >> k;
    l = 0, r = 5e11;
    for(; l + 1 < r; ){
        mid = (l + r) / 2ll;
        cnt = 0ll;
        for(i = 1; i <= n; i++){
            v = min(m, mid / i);
            cnt += v;
        }
        if (cnt < k){
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << r << endl;
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