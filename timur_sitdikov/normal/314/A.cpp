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

const int MAXN = 200005;

long long a;

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    long long i, j, n, sum, sum1, k;
    scanf("%I64d %I64d", &n, &k);
    sum = 0;
    for(j = 0, i = 1; i <= n; i++){
        scanf("%I64d", &a);
        sum1 = sum - j * (n - i) * a;
        if (sum1 < k){
            printf("%I64d\n", i);
        }
        else{
            sum += j * a;
            j++;
        }
    }
}