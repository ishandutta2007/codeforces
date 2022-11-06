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

vector<int> ans;

void solve(){
    int n, i;
    cin >> n;
    while(n){
        int v = n, v1 = 0, st10 = 1;
        for(; v; v /= 10, st10 *= 10){
            if (v % 10){
                v1 += st10;
            }
        }
        ans.pb(v1);
        n -= v1;
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(i = 0; i < (int)ans.size(); i++){
        printf("%d ", ans[i]);
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