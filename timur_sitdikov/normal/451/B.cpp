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

const int MAXN = 1e5 + 5;
const int INF = 1e9 + 9;

int v[MAXN];

void solve(){
    int n, l, r, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }
    v[n + 1] = INF;
    l = -1;
    for(i = 1; i <= n + 1; i++){
        if (v[i] < v[i - 1]){
            l = i - 1;
            break;
        }
    }
    if (l == -1){
        printf("yes\n1 1\n");
        return;
    }
    for(i = l + 1; i <= n + 1; i++){
        if (v[i] > v[i - 1]){
            r = i - 1;
            break;
        }
    }
    for(i = r + 1; i <= n + 1; i++){
        if (v[i] < v[i - 1]){
            printf("no\n");
            return;
        }
    }
    if (v[r] > v[l - 1] && v[l] < v[r + 1]){
        printf("yes\n%d %d\n", l, r);
    } else {
        printf("no\n");
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