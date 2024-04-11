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
    long long h, r, ans, x1, y1, x2, y2, tmp, dd;
    cin >> r >> h;
    r *= 2;
    h *= 2;
    tmp = h + r / 2;
    ans = 2 * (tmp / r);
    x1 = r;
    y1 = tmp;
    x2 = r / 2;
    y2 = (tmp - tmp % r) - r / 2;
    dd = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    if (dd >= r * r){
        ans++;
    }
    cout << ans;
}