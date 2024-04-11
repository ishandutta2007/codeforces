/*
 - - - - - - - -
 
   *******
 ***********
 ***     ***
 ***
 ***
 ***
 ***
 ***     ***
 ***********
   *******
 
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

int n;
long long arr[200001];

double z(int i, double X) {
    return X * i + arr[i];
}

double max(double X) {
    double ans = arr[1] + X;
    int L = 0;
    //cout << endl;
    For(i, 1, n + 1) {
        //cout << ans << ' ' << L << endl;
        double s = z(i, X) - z(L, X);
        if (z(i, X) < z(L, X)) L = i;
        if (ans < s) ans = s;
        //cout << ans << ' ' << L << endl;
    }
    return ans;
}

double min(double X) {
    double ans = arr[1] + X;
    int L = 0;
    For(i, 1, n + 1) {
        double s = z(i, X) - z(L, X);
        if (z(i, X) > z(L, X)) L = i;
        if (ans > s) ans = s;
    }
    return ans;
}

double f(double X) {
    double ans1 = -min(X), ans2 = max(X);//cout << ans1 << '!' << ans2 << endl;
    if (ans1 < ans2) return ans2;
    return ans1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n; For(i, 0, n) cin >> arr[i + 1];
    For(i, 1, n + 1) arr[i] = arr[i] + arr[i - 1];
    double L = -1e5, R = 1e5, M1 = 0, M2 = 0;
    For(i, 0, 100) {
        M1 = (L * 2 + R) / 3;
        M2 = (R * 2 + L) / 3;
        if (f(M1) > f(M2)) {
            L = M1;
        } else {
            R = M2;
        }
    }
    cout << fixed << f(L);
}