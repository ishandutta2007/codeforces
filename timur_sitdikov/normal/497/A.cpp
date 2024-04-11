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

const int MAXN = 105;

char c[MAXN][MAXN], c1[MAXN][MAXN];

void solve(){
    int n, m, i, j, k, ans;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++){
        scanf("%s", &c[i][0]);
    }
    ans = 0;
    for(j = 0; j < m; j++){
        for(i = 0; i < n; i++){
            c1[i][ans] = c[i][j];
        }
        int fl = 0;
        for(i = 1; i < n; i++){
            if (strcmp(c1[i - 1], c1[i]) == 1){
                fl = 1;
                break;  
            }
        }
        if (!fl){
            ans++;
        }
    }
    ans = m - ans;
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