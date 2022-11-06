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

string FileName = "alarm";

typedef long long base;

int n, m;
int LR[2][2];
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    LR[0][0] = LR[1][0] = 1e9;
    For(i, 0, n) {
        For(j, 0, m) {
            char a; cin >> a;
            if (a == '.') continue;
            LR[0][0] = min(LR[0][0], i);
            LR[0][1] = max(LR[0][1], i);
            LR[1][0] = min(LR[1][0], j);
            LR[1][1] = max(LR[1][1], j);
        }
    }
    cout << max(LR[0][1] - LR[0][0], LR[1][1] - LR[1][0]) + 1;
}