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

int n, X, Y;
vector <int> arr;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> X >> Y;
    For(i, 0, n) {
        int a; cin >> a;
        arr.pb(a);
    }
    sort(arr.begin(), arr.end());
    For(i, 0, n) {
        if ((arr[i] & 1) && Y) {
            --Y; --arr[i];
        }
        arr[i] = (arr[i] + 1) / 2;
        int Z = min(arr[i], X);
        arr[i] -= Z;
        X -= Z;
        arr[i] *= 2;
        if (arr[i] > Y) {
            cout << i << endl;
            return 0;
        }
        Y -= arr[i];
    }
    cout << n << endl;
}