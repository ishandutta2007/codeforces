#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <base, base>
#define x first
#define y second

using namespace std;

typedef long long base;

int n;
bool arr[101];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) cin >> arr[i];
    For(i, 0, n) {
        if (arr[i]) break;
        arr[i] = 1;
        if (i == n - 1) {
            cout << 0 << endl;
            return 0;
        }
    }
    Out(i, n, 0) {
        if (arr[i]) break;
        arr[i] = 1;
    }
    base ans = 1;
    base cnt = 0;
    For(i, 0, n) {
        if (arr[i]) {
            ans *= (cnt + 1);
            cnt = 0;
        } else {
            ++cnt;
        }
    }
    cout << ans << endl;
}