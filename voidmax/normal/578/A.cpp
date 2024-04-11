/*
 - - - - - - - -
 
  *********
 ***********
 ***     ***
 ***     ***
 ***     ***
 ***********
 ***********
 ***     ***
 ***     ***
 ***     ***
 
 - - - - - - - -
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define pb push_back
#define inf 1e9
#define x first
#define y second

using namespace std;

double a, b;
double ans1, ans2;

int main() {
    cin >> a >> b;
    if (a < b) {
        cout << -1;
        return 0;
    }
    ans1 = (double)(a + b) / 2;
    int L = 0, R = 1e9 + 8e8, M = 0;
    while (R - L > 1) {
        M = (L + R) >> 1;
        if (ans1 > M * b - 1e-9) {
            L = M;
        } else {
            R = M;
        }
    }
    if (L == 0) {
        ans1 = 1e9;
    } else {
        ans1 = ans1 / L;
    }
    ans2 = (double)(a - b) / 2;
    L = 0, R = 1e9 + 8e8, M = 0;
    while (R - L > 1) {
        M = (L + R) >> 1;
        if (ans2 > M * b - 1e-9) {
            L = M;
        } else {
            R = M;
        }
    }
    if (L == 0) {
        ans2 = 1e9;
    } else {
        ans2 = ans2 / L;
    }
    //cout << ans1 << ' ' << ans2 << endl;
    printf("%.9f", min(max(0.0, ans1), max(0.0, ans2)));
}