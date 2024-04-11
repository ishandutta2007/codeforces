#include <bits/stdc++.h>
using namespace std;

const int N = 132674 + 1;

array<int, 4> rect[N], prefix[N], suffix[N];

array<int, 4> intersect(array<int, 4> a, array<int, 4> b) {
    return {
        max(a[0], b[0]),
        max(a[1], b[1]),
        min(a[2], b[2]),
        min(a[3], b[3])
    };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (auto &j : rect[i]) {
            cin >> j;
        }
    }

    prefix[0] = suffix[n] = {INT_MIN, INT_MIN, INT_MAX, INT_MAX};

    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = intersect(prefix[i], rect[i]);
    }

    for (int i = n - 1; i >= 0; --i) {
        suffix[i] = intersect(suffix[i + 1], rect[i]);
    }

    for (int i = 0; i < n; ++i) {
        array<int, 4> point = intersect(prefix[i], suffix[i + 1]);
        if (point[0] <= point[2] && point[1] <= point[3]) {
            cout << point[0] << " " << point[1] << "\n";
            exit(0);
        }
    }
}