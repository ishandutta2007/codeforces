
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
vector <pair <int, pair <int, int>>> arr;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {
        char a;
        int b, c;
        cin >> a >> b >> c;
        arr.push_back({b, {-1, a == 'F'}});
        arr.push_back({c, {1, a == 'F'}});
    }
    sort(arr.begin(), arr.end());
    int b[2]; b[0] = b[1] = 0;
    int ans = 0;
    For(i, 0, arr.size()) {
        b[arr[i].y.y] -= arr[i].y.x;
        ans = max(ans, min(b[0], b[1]));
    }
    cout << ans * 2 << endl;
}