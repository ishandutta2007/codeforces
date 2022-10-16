#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <cassert>

using namespace std;

const int N = 2e5+7;
const int S = 1 << 20;

int n, k, sz = S, t[2*S], counter;

void change(int i, int x) {
    for (t[i += sz] += x; i != 1; ) t[i >>= 1] += x;
}

int sum(int l, int r) {
    int q = 0;
    for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
        if ((l&1) == 1) q += t[l++];
        if ((r&1) == 0) q += t[r--];
    }
    return q;
}

int ask(int l, int r) {
    ++counter;
    cout << "? " << l << " " << r << endl;

    // return _ask(l, r);

    int x; cin >> x;
    return (r - l + 1) - x;
}

void ans(int x) {
    cout << "! " << x << endl;
}

int lb(int x) {
    int l = 0, r = sz;
    while (l < r) {
        int m = (l + r) / 2;
        if (sum(0, m) < x) l = m + 1;
        else r = m;
    }

    return r;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k; sz = (n+31)/32;

    for (int num = 1; num <= k; ++num) {
        int _x; cin >> _x; const int x = _x;

        if (num == 1) {
            for (int i = 0; i < sz; ++i) {
                const int r = (i + 1) * 32;
                change(i, ask(r - 31, min(n, r)));
            }
        }

        int block = lb(x);
        int l = 1 + 32 * block, r = min(n, 32 + 32 * block);
        while (l < r) {
            int m = (l + r) / 2;
            if (ask(1, m) < x) l = m + 1;
            else r = m;
        }

        ans(r);
        change((r-1)/32, -1);
    }

    cerr << "Got " << counter << " queries" << endl;
}