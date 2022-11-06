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
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

const int MAXN = 100005;
long long v[3][MAXN], st[MAXN], f[MAXN];

long long t[3], k[3];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    long long n, i, j, last, mx;
    for(j = 0; j < 3; j++){
        scanf("%I64d", &k[j]);
    }
    for(j = 0; j < 3; j++){
        scanf("%I64d", &t[j]);
    }
    scanf("%I64d", &n);
    for(i = 0; i < n; i++){
        scanf("%I64d", &st[i]);
    }
    sort(st, st + n);
    for(i = 0; i < n; i++){
        last = st[i];
        for(j = 0; j < 3; j++){
            if (i >= k[j] && v[j][i - k[j]] > last){
                last = v[j][i - k[j]];
            }
            v[j][i] = last + t[j];
            last = v[j][i];
        }
        f[i] = last;
    }
    mx = 0;
    for(i = 0; i < n; i++){
        if (f[i] - st[i] > mx){
            mx = f[i] - st[i] ;
        }
    }
    printf("%I64d", mx);
}