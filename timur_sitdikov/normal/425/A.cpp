#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

#define FILE "file"

const int MAXN = 205;

const int INF = 1e9;

int m[MAXN], m1[MAXN], m2[MAXN], m3[MAXN];


void solve(){
    int n, k, i, j, l, l1;
    cin >> n >> k;
    for(i = 0; i < n; i++){
        cin >> m[i];
        m3[i] = m[i];
    }
    int top1, top2, top3, sum1, sum2;
    int ans = -INF;
    sort(m3, m3 + n);
    reverse(m3, m3 + n);
    int cc = 0;
    for(i = 0; i < k; i++){
        cc += m3[i];
        ans = max(ans, cc);
    }
    for(i = 0; i < n; i++){
        for(j = i - 1; j < n; j++){
            top1 = top2 = 0;
            for(l = 0; l < n; l++){
                if (l < i || l > j){
                    m1[top1++] = m[l];
                }
                else {
                    m2[top2++] = m[l];
                }
            }
            sort(m1, m1 + top1);
            sort(m2, m2 + top2);
            sum1 = sum2 = 0;
            for(l = k; l < top2; l++){
                sum2 += m2[l];
            }
            top3 = 0;
            int lim1, lim2;
            lim1 = min(k, top1);
            lim2 = min(k, top2);
            top3 = lim1 + lim2;
            merge(m1 + top1 - lim1, m1 + top1, m2, m2 + lim2, m3);
            for(l = top3 - 1, l1 = 0; l1 < k && l >= 0; l--, l1++){
                sum1 += m3[l];
            }
        /*  if (i == 0 && j == n - 1){
                cout << sum2 << " " << sum1 << endl;
            }*/
            if (ans < sum1 + sum2){
                ans = sum1 + sum2;
            //  printf("%d %d %d %d\n", i, j, sum2, sum1);
            }
        }
    }
    cout << ans;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //assert(freopen(FILE ".in", "r", stdin));assert(freopen(FILE ".out", "w", stdout));
    int t = 1;
    while(t){
        t--;
        solve();
    }
}