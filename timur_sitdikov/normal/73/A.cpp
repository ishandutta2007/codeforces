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

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long n, k, x[3], v;
    cin >> x[0] >> x[1] >> x[2] >> k;
    sort(x, x + 3);
    v = k / 3;
    n = 1;
    if (v >= x[0]){
        v = x[0] - 1;
    }
    n *= (v + 1);
    k -= v;
    v = k / 2;
    if (v >= x[1]){
        v = x[1] - 1;
    }
    n *= (v + 1);
    k -= v;
    v = k;
    if (v >= x[2]){
        v = x[2] - 1;
    }
    n *= (v + 1);
    cout << n;
}