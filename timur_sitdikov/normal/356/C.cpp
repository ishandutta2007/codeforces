#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

const int MAXN = 1000005;
const int INF = 1000000000;
int c[5], cr[5];

void solve(){
    int i, j, n, a, s, cnt, cnt1, add, ans, cur;
    scanf("%d",&n);
    s = 0;
    for(i = 0; i < n; i++){
        scanf("%d", &a);
        c[a]++;
        s += a;
    }
    ans = INF;
    for(i = 0; i * 3 <= s; i++){
        cr[3] = i;
        cr[4] = s - 3 * i;
        if (cr[4] % 4){
            continue;
        }
        cr[4] /= 4;
        cnt = cr[3] + cr[4];
        if (cnt > n){
            continue;
        }
        cur = 0;
        cnt1 = n - cnt;
        for(j = 0; j < 5; j++){
            add = min(cnt1, c[j]);
            cur += add * j;
            cnt1 -= add;
        }
        if (cr[4] < c[4]){
            cur += c[4] - cr[4];
        }
        if (cur < ans){
            ans = cur;
        }
    }
    if (ans == INF){
        ans = -1;
    }
    printf("%d", ans);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);  
    freopen("out.txt", "w", stdout);
#endif
    int t;
    t = 1;
    while(t){
        t--;
        solve();
    }
}