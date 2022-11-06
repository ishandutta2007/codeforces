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
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

long long c[50][50], bit[50];

int is_good(long long v){
    for(; ; v /= 2){
        if (v & 1)
            break;
    }
    return v == 1;
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long i, j, len, cnt, tt, aa;
    for(i = 0; i < 50; i++)
        c[i][0] = c[i][i] = 1;
    for(i = 1; i < 50; i++){
        for(j = 1; j < i; j++){
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    long long n, t;
    cin >> n >> t;
    if (!is_good(t)){
        cout << 0;
        return 0;
    }
    tt = t;
    for(cnt = 0; t > 1; cnt++)
        t /= 2;
    cnt++;
    long long ans = 0;
    n++;
    aa = 0;
    for(i = 0; n; i++){
        bit[i] = n & 1;
        n /= 2;
        aa += bit[i];
    }
    if (aa == cnt)
        ans = 1;
    len = i;
    for(i = len - 1; i >= 0; i--){
        if (bit[i]){
            ans += c[i][cnt];
            cnt--;
            if (cnt < 0)
                break;
        }
    }
    if (tt == 1)
        ans--;
    cout << ans;
}