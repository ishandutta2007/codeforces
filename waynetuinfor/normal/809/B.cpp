#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int bs(int, int);
bool query(int, int);

int main() {
    int n, k; cin >> n >> k;
    int x = bs(1, n );
    int y = bs(1, x - 1);
    if (!query(y, x)) y = bs(x + 1, n);
    assert(x >= 1 && x <= n && y >= 1 && y <= n);
    cout << 2 << ' ' << x << ' ' << y << endl;
    return 0;
}

int bs(int l, int r) {
    if (l > r) return -1;
    while (l < r) {
        int m = (l + r) >> 1;
        if (query(m, m + 1)) r = m;
        else l = m + 1;
    }
    return l;
}

bool query(int l, int r) {
    if (l == -1) return false;
    cout << 1 << ' ' << l << ' ' << r << endl;
    string s; cin >> s;
    return s == "TAK";
}