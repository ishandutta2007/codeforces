//#include "grader.h"
#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <base, base>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "input";

typedef long long base;

int n, m, k;
int b[2];
int a[2][2];

int UpDown(int n) {
    return min(n * 5, 10 + n);
}

int Dist(int u, int v) {
    if (u > v) return Dist(v, u);
    return min(v - u, n + u - v);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    cin >> b[0] >> b[1]; --b[0]; --b[1];
    b[0] /= k; b[1] /= k;
    a[0][0] = b[0] / m;
    a[1][0] = b[0] % m;
    a[0][1] = b[1] / m;
    a[1][1] = b[1] % m;
    if (a[0][0] != a[0][1])
        cout << Dist(a[0][1], a[0][0]) * 15 + UpDown(a[1][1]) + UpDown(a[1][0]);
    else
        cout << UpDown(abs(a[1][1] - a[1][0]));
}