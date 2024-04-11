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
    long long a, mod, i, n;
    mod = 1000003;
    cin >> n;
    if (n == 0){
        printf("1");
        return 0;
    }
    a = 1;
    for(i = 1; i < n; i++){
         a = (a * 3) % mod;
    }
    cout << a;
}