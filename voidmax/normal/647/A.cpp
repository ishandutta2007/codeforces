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

int n;
int cnt;
int ans;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {
        int a; cin >> a;
        if (a >= 4) {
            ++cnt;
            if (cnt == 3) {
                ++ans; cnt = 0;
            }
        } else {
            cnt = 0;
        }
    }
    cout << ans << endl;
}