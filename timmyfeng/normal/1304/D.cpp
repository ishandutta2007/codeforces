#include <bits/stdc++.h>
using namespace std;

vector<int> ft;
int n;

int sum(int r) {
    int ret = 0;
    for ( ; r; r -= r & -r) {
        ret += ft[r];
    }
    return ret;
}

void update(int ndx, int val) {
    for ( ; ndx <= n; ndx += ndx & -ndx) {
        ft[ndx] += val;
    }
}

void init() {
    ft.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        update(i, 1);
    }
}

int pop(int ndx) {
    int hi = n;
    int lo = 1;
    while (lo < hi) {
        int mi = (lo + hi) / 2;
        if (sum(mi) < ndx) {
            lo = mi + 1;
        } else {
            hi = mi;
        }
    }
    update(lo, -1);
    return lo;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> n >> s;
        vector<int> ndx(n);
        ndx[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '<') {
                ndx[i] = ndx[i + 1] + 1;
            } else {
                ndx[i] = 1;
            }
        }
        init();
        for (int i = 0; i < n; i++) {
            cout << pop(sum(n) - ndx[i] + 1) << ' ';
        }
        cout << '\n';
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '>') {
                ndx[i] = ndx[i + 1] + 1;
            } else {
                ndx[i] = 1;
            }
        }
        init();
        for (int i = 0; i < n; i++) {
            cout << pop(ndx[i]) << ' ';
        }
        cout << '\n';
    }
}