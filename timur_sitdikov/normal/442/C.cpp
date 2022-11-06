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

const int MAXN = 500005;

int v[MAXN];

void solve(){
    int i, top, n;
    scanf("%d", &n);
    top = 1;
    ll ans = 0;
    for(i = 1; i <= n; i++){
        scanf("%d", &v[top]);
        while(top > 1 && v[top] >= v[top - 1] && v[top - 1] <= v[top - 2]){
            ans += min(v[top], v[top - 2]);
            v[top - 1] = v[top];
            top--;
        }
        top++;
    }
    sort(v + 1, v + top);
    for(i = 1; i < top - 2; i++){
        ans += v[i];
    }
    cout << ans << endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = 1;
    while(t--){
        solve();    
    }
}