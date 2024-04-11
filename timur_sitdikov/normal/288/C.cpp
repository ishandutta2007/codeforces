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

const int MAXN = 1000005;
int p[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, j, k, n1;
    long long ans;
    scanf("%d", &n);
    n1 = n;
    while(1){
        if (n1 <= 0)
            break;
        for(i = 1; i <= n1; i <<= 1);
        i >>= 1;
        if (i == 0)
            break;
        k = 2 * i - n1 - 1;
        for(j = n1; j >= k; j--){
            p[j] = (i << 1) - 1 - j;
        }
        n1 = k - 1;
    }
    ans = 0;
    for(i = 0; i <= n; i++){
        ans += (long long)(p[i] ^ i);
    }
    printf("%I64d\n", ans);
    for(i = 0; i <= n; i++){
        printf("%d ", p[i]);
    }

}