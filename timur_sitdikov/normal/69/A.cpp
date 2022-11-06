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
    int n, i, x, y, z, a, b, c;
    x = y = z = 0;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> a >> b >> c;
        x += a;
        y += b;
        z += c;
    }
    if (x || y || z){
        printf("NO");
    }
    else{
        printf("YES");
    }
}