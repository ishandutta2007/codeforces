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

const int MAXN = 70005;

char fr[MAXN];
int v[MAXN], top;
pair<int, int> vals[MAXN];
int ans[MAXN];
int contains[MAXN];
unsigned goods[MAXN / 32 + 5];
int prv[MAXN];

void set_prv(int qq, int rr, int ind){
    prv[qq * 32 + rr] = ind;
}

void solve(){
    int n, s, i, j, k, maxi, mx, lim, tmp, offset;
    unsigned mask, mask1;
    scanf("%d%d", &n, &s);
    /*const int VV = 70000;
    n = s = VV;*/
    for(i = 1; i <= n; i++){
        scanf("%d", &v[i]);
        //v[i] = 1;
    }
    mx = -1;
    for(i = 1; i <= n; i++){
        if (v[i] > mx){
            mx = v[i];
            maxi = i;
        }
    }
    if (mx > s){
        printf("-1");
        return;
    }
    lim = s - mx;
    goods[0] = 1;
    for(i = 1; i <= n; i++){
        if (i == maxi){
            continue;
        }
        int offset = v[i] % 32;
        for(j = (lim - v[i]) / 32; j >= 0; j--){
            if (offset != 0){
                mask = (goods[j + v[i] / 32 + 1] | (goods[j] >> (32 - offset)));
                if (mask != goods[j + v[i] / 32 + 1]){
                    mask1 = (mask & (~goods[j + v[i] / 32 + 1]));
                    for(k = 0; mask1; k++){
                        if (mask1 & 1){
                            set_prv(j + v[i] / 32 + 1, k, i);
                        }
                        mask1 >>= 1;
                    }
                    goods[j + v[i] / 32 + 1] = mask;
                }
            }
            mask = (goods[j + v[i] / 32] | (goods[j] << offset));
            if (mask != goods[j + v[i] / 32]){
                mask1 = (mask & (~goods[j + v[i] / 32]));
                for(k = 0; mask1; k++){
                    if (mask1 & 1){
                        set_prv(j + v[i] / 32, k, i);
                    }
                    mask1 >>= 1;
                }
                goods[j + v[i] / 32] = mask;
            }
            
        }
    }
    if (lim && prv[lim] == 0){
        printf("-1");
        return;
    }
    for(i = 1; i <= n; i++){
        fr[i] = 0;
    }
    for(j = lim; j > 0; ){
        fr[prv[j]] = 1;
        ans[prv[j]] = v[prv[j]];
        j -= v[prv[j]]; 
    }
    top = 0;
    for(i = 1; i <= n; i++){
        if (!fr[i]){
            vals[top++] = mp(v[i], i);
        }
    }
    for(i = 1; i <= n; i++){
        contains[i] = 0;
    }
    sort(vals, vals + top);
    ans[vals[0].second] = vals[0].first;
    for(i = 1; i < top; i++){
        ans[vals[i].second] = vals[i].first - vals[i - 1].first;
        contains[vals[i].second] = vals[i - 1].second;
    }
    for(i = 1; i <= n; i++){
        printf("%d ", ans[i]);
        if (contains[i]){
            printf("1 %d\n", contains[i]);
        }
        else {
            printf("0\n");
        }
    }
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