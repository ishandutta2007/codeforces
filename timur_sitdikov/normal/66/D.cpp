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
#define xx first
#define yy second

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long n, i, j, v;
    cin >> n;
    if (n == 2){
        printf("-1");
        return 0;
    }
    printf("6\n10\n15\n");
    for(i = 4; i <= n; i++){
        v = 6;
        for(j = 4; j <= i; j++)
            v *= 2;
        printf("%I64d\n", v);
    }
}