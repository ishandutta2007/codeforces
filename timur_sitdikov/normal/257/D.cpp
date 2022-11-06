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

int a[maxn];
char sign[maxn], sym[200];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i, v;
    cin >> n;
    sym[0] = '+';
    sym[1] = '-';
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = n - 2; i >= 0; i--){
        sign[i + 1] ^= 1;
        if (a[i + 1] < a[i]){
            a[i] -= a[i + 1];
        }
        else{
            sign[i] ^= 1;
            a[i] = a[i + 1] - a[i];
        }
    }
    v = 0;
    for(i = 0; i < n; i++){
        v ^= sign[i];
        putchar(sym[v]);
    }
}