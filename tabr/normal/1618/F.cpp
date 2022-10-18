#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

bool check(long long x, long long y) {
    vector<int> a;
    while (x > 0) {
        if (x % 2 == 1) {
            a.emplace_back(1);
        } else {
            a.emplace_back(0);
        }
        x /= 2;
    }
    vector<int> b;
    while (y > 0) {
        if (y % 2 == 1) {
            b.emplace_back(1);
        } else {
            b.emplace_back(0);
        }
        y /= 2;
    }
    if (a.size() > b.size()) {
        return false;
    }
    for (int z = 0; z < 2; z++) {
        int c = (int) b.size() - (int) a.size();
        for (int i = 0; i <= c; i++) {
            vector<int> d = a;
            for (int j = 0; j < i; j++) {
                d.emplace_back(1);
            }
            for (int j = i; j < c; j++) {
                d.insert(d.begin(), 1);
            }
            if (d == b) {
                return true;
            }
        }
        reverse(b.begin(), b.end());
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long x, y;
    cin >> x >> y;
    if (x == y) {
        cout << "YES" << '\n';
        return 0;
    }
    if (y % 2 == 0) {
        cout << "NO" << '\n';
        return 0;
    }
    if (check(x * 2 + 1, y)) {
        cout << "YES" << '\n';
        return 0;
    }
    while (x % 2 == 0) {
        x /= 2;
    }
    if (check(x, y)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}