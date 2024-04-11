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

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, t, i, lt, c, mx, cur, ff;
    scanf("%d", &n);
    lt = 0;
    mx = cur = 0;
    for(i = 0; i < n; i++){
        scanf("%d %d", &t, &c);
        cur = max(0, cur - (t - lt)) + c;
        mx = max(mx, cur);
        lt = t;
    }
    ff = t + cur;
    printf("%d %d\n", ff, mx);
}