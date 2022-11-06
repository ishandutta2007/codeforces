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

int n;
int r = 0, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {
        int a; cin >> a;
        while (a % (1 << (r + 1)) == 0) {
            cnt = 0; ++r;
        }
        if ((a % (1 << r)) == 0) {
            ++cnt;
        }
    }
    cout << (1 << r) << ' '  << cnt << endl;
}