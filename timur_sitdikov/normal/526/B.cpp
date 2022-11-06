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

const int MAXN = 1e4;

int v[MAXN], s[MAXN];

void solve(){
    int n, i, cnt;
    cin >> n;
    cnt = 1 << (n + 1);
    for(i = 2; i < cnt; i++){
        cin >> v[i];
    }
    int ans = 0;
    for(i = cnt - 1; i > 0; i--){
        int v1 = v[i << 1] + s[i << 1];
        int v2 = v[(i << 1) + 1] + s[(i << 1) + 1];
        ans += abs(v2 - v1);
        s[i] = max(v1, v2);
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