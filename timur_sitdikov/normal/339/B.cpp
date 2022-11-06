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


int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    long long ans = 0;
    int i, a, b, a1, b1, n, m, v;
    scanf("%d%d", &n, &m);
    a = 1;
    for(i = 1; i <= m; i++){
        scanf("%d", &b);
        if (a <= b){
            ans += b - a;
        }
        else {
            ans += (n + b - a);
        }
        a = b;
    }
    printf("%I64d", ans);
}