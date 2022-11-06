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

const int maxn = 100005, inf = 1000000005;
int cost[maxn];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m, n, q, i, a, sum;
    cin >> m;
    q = inf;
    for(i = 0; i < m; i++){
        cin >> a;
        q = min(q, a);
    }
    cin >> n;
    sum = 0;
    for(i = 0; i < n; i++){
        cin >> cost[i];
        sum += cost[i];
    }
    sort(cost, cost + n);
    reverse(cost, cost + n);
    for(i = 0; i < n; i += (q + 2)){
        if (i + q < n)
            sum -= cost[i + q];
        if (i + q + 1 < n)
            sum -= cost[i + q + 1];
    }
    printf("%d", sum);
}