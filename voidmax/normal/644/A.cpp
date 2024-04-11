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

int n, a, b;
int L[2] = {0, 1};
int ans[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    if (a * b < n) {
        cout << -1 << endl;
        return 0;
    }
    For(i, 0, a) {
        For(j, 0, b) {
            int c = (i + j) & 1;
            if (L[c] >= n) {
                continue;
            }
            ans[i][j] = L[c] + 1;
            L[c] += 2;
        }
    }
    For(i, 0, a) {
        For(j, 0, b) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}