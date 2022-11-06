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
    int ans, i, n, m, a, b, d1, d2;
    scanf("%d%d%d%d", &n, &m, &d1, &a);
    ans = a + d1 - 1;
    for(i = 1; i < m; i++){
        scanf("%d%d", &d2, &b);
        if (abs(a - b) > d2 - d1){
            printf("IMPOSSIBLE\n");
            return;
        }
        ans = max(ans, (a + b + d2 - d1) / 2);
        d1 = d2;
        a = b;
    }
    ans = max(ans, a + n - d1);
    printf("%d\n", ans); 

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