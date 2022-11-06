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

#define file "permutation"

const int MAXN = 2e5 + 5;

int w[MAXN], h[MAXN];

void solve(){
    int n, i, maxi1, maxi2;
    ll mx1, mx2, ww, ans;
    scanf("%d", &n);
    ww = mx1 = mx2 = 0;
    for(i = 0; i < n; i++){
        scanf("%d%d", &w[i], &h[i]);
        ww += w[i];
        if (h[i] > mx1){
            mx1 = h[i];
            maxi1 = i;  
        }
    }
    for(i = 0; i < n; i++){
        if (i != maxi1 && h[i] > mx2){
            mx2 = h[i];
            maxi2 = i;
        }
    }
    for(i = 0; i < n; i++){
        ans = ww - w[i];
        if (i == maxi1){
            ans *= mx2;
        } else {
            ans *= mx1;
        }
        printf("%I64d ", ans);
    }


}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //scanf("%d", &t);
    while(t--){
        solve();    
    }
}