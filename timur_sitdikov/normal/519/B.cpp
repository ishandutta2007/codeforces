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

const int MAXN = 3e5 + 5;

int a[MAXN], b[MAXN], c[MAXN];

void solve(){
    int n, i, ans[2];
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n - 1; i++){
        scanf("%d", &b[i]);
    }
    for(i = 0; i < n - 2; i++){
        scanf("%d", &c[i]);
    }
    sort(a, a + n);
    sort(b, b + n - 1);
    sort(c, c + n - 2);
    for(i = 0; i < n; i++){
        if (a[i] != b[i]){
            ans[0] = a[i];
            break;
        }
    }
    for(i = 0; i < n - 1; i++){
        if (b[i] != c[i]){
            ans[1] = b[i];
            break;
        }
    }
    printf("%d\n%d\n", ans[0], ans[1]);
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