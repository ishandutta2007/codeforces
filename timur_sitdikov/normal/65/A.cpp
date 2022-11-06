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
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (b * d * f > e * a * c || a == 0 && b * d != 0 || c ==0 && d != 0){
        cout << "Ron";
    }
    else cout << "Hermione";
}