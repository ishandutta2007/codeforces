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

int n;
base k;
base a[300002];
base inf = 1e17 + 7;
base cnt[300002];


int main() {
    //files(FileName);
    ios::sync_with_stdio(false);
    cin >> n >> k; ++n;
    For(i, 0, n) cin >> a[i];
    Out(i, n, 0) {
        cnt[i] = (cnt[i + 1] + a[i + 1]) << 1;
        if (abs(cnt[i]) > inf) {
            cnt[i] = inf;
        }
    }
    int ans = 0;
    base Sum = 0;
    For(i, 0, n) {
        cnt[i] += Sum;
        if (abs(cnt[i]) <= k) {
            if (!(i == n - 1 && cnt[i] == 0)) {
                ++ans;
            }
        }
        Sum += a[i];
        if (Sum & 1) break;
        Sum >>= 1;
    }
    cout << ans << endl;
}