//#include "grader.h"
#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "minsumdiff";

typedef long long base;

int d, h, n;

int main() {
    //files(FileName);
    ios::sync_with_stdio(false);
    cin >> n >> d >> h;
    if (d < h || h + h < d) {
        cout << -1 << endl;
        return 0;
    }
    if (d > n) {
        cout << -1 << endl;
        return 0;
    }
    if (d == 1) {
        if (n != 2 || h != 1) {
            cout << -1 << endl;
            return 0;
        } else {
            cout << 1 << ' ' << 2 << endl;
            return 0;
        }
    }
    if (h == 1) {
        if (d > 2) {
            cout << -1 << endl;
            return 0;
        }
    }
    int cnt = 1;
    int k = d - h;
    For(i, 0, h) {
        cout << cnt << ' ' << cnt + 1 << endl;
        ++cnt;
    }
    ++cnt;
    if (k != 0) {
        cout << 1 << ' ' << cnt << endl;
        For(i, 0, k - 1) {
            cout << cnt << ' ' << cnt + 1 << endl;
            ++cnt;
        }
        ++cnt;
        while (cnt <= n) {
            cout << 1 << ' ' << cnt << endl;
            ++cnt;
        }
    } else {
        while (cnt <= n) {
            cout << 2 << ' ' << cnt << endl;
            ++cnt;
        }
    }
}