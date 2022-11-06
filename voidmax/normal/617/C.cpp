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
point a, b;
base ans[2];
base cnt = 1e18;

base dist(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool cmp(point b, point c) {
    return dist(a, b) < dist(a, c);
}

vector <point> arr[2];

int main() {
    cin >> n >> a.x >> a.y >> b.x >> b.y;
    For(i, 0, n) {
        point c; cin >> c.x >> c.y;
        arr[0].push_back(c);
    }
    sort(arr[0].begin(), arr[0].end(), cmp);
    while (true) {
        ans[0] = ans[1] = 0;
        For(i, 0, arr[0].size()) {
            ans[0] = max(ans[0], dist(a, arr[0][i]));
        }
        For(i, 0, arr[1].size()) {
            ans[1] = max(ans[1], dist(b, arr[1][i]));
        }
        cnt = min(cnt, ans[0] + ans[1]);
        if (arr[0].size() == 0) break;
        arr[1].push_back(arr[0][(int)arr[0].size() - 1]);
        arr[0].pop_back();
    }
    cout << cnt << endl;
}