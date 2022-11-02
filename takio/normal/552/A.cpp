#include <stdio.h>
#include <map>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std ;

int n;

int main () {
    int n, res = 0, a, b, c, d;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c >> d;
        res += (c - a + 1) * (d - b + 1);
    }
    cout <<res << endl;
}