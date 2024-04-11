
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
string arr[101];
int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) cin >> arr[i];
    For(i, 0, n) {
        int cnt = 0;
        For(j, 0, n) cnt += (arr[i][j] == 'C');
        ans += cnt * (cnt - 1) / 2;
    }
    For(j, 0, n) {
        int cnt = 0;
        For(i, 0, n) cnt += (arr[i][j] == 'C');
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans << endl;
}