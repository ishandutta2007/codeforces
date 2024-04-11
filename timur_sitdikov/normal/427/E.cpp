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

#define FILE "file"
#define ll long long

const int MAXN = 1000005;


const ll INF = 1e17;
int d[MAXN];
vector<int> sl, sr;

void solve(){
    int n, m, i, j;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++){
        scanf("%d", &d[i]);
    }
    ll ans = INF, cur = 0;
    for(i = 0; i < n - 1; i += m){
        sl.pb(d[i]);
        cur += d[n - 1] - d[i];
    }
    sr.pb(d[n - 1]);
    ans = min(ans, cur);
    for(i = n - 2; i >= 0; i--){
        cur -= (ll)sl.size() * (d[i + 1] - d[i] + 0ll);
        cur += (ll)sr.size() * (d[i + 1] - d[i] + 0ll);
        if (i % m == 0){
            sl.pop_back();
        }
        if ((n - 1 - i) % m == 0){
            sr.pb(d[i]);
        }
        ans = min(ans, cur);
    }
    cout << ans * 2ll;
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