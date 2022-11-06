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

const int MAXN = 2e5 + 5;

int ans[MAXN], a[MAXN], v1[MAXN], v2[MAXN];

void solve(){
    int i, j, k, n, sq, tmp, last;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    /*n = 2e5;
    for(i = 1; i <= n; i++){
        a[i] = n - i;
    }*/
    for(i = 2; i <= n; i++){
        sq = (int)sqrt(i + 0.5);
        for(j = 1; ; j++){
            tmp = (i - 2) / j + 1;
            if (tmp <= sq){
                break;
            }
            if (a[tmp] > a[i]){
                ans[j]++;
            }
        }
        last = j;
        for(j = sq; j >= 1; j--){
            if (j == 1){
                tmp = n - 1;
            } else {
                tmp = (i - 2) / (j - 1);
            }
            if (a[j] > a[i]){
                v1[last]++;
                v2[tmp]++;
            }
            last = tmp + 1;
        }
    }
    int cur = 0;
    for(i = 1; i < n; i++){
        cur += v1[i];
        printf("%d ", ans[i] + cur);
        cur -= v2[i];
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