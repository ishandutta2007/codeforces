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

const int maxn = 100005;
int c[maxn];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i, d, q, j, s;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &c[i]);
    for(d = 3; d <= n; d++){
        if (n % d)
            continue;
        q = n / d;
        for(j = 0; j < q; j++){
            s = 0;
            for(i = j; i < n; i += q){
                s += c[i];
            }
            if (s == d){
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
}