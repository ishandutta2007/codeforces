#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int Solve(vector<int> p) {
    int m = (int) p.size();
    if (m <= 1) {
        return 0;
    }
    int q = (int) (min_element(p.begin(), p.end()) - p.begin());
    for (int i = 0, j = p[q]; i < m; i++) {
        p[i] -= j;
    }
    auto r = p;
    sort(r.begin(), r.end());
    if (r[m - 1] != m - 1) {
        return -1;
    }
    vector<int> p0(p.begin(), p.begin() + m / 2);
    vector<int> p1(p.begin() + m / 2, p.end());
    int x = Solve(p0), y = Solve(p1);
    if (min(x, y) == -1) {
        return -1;
    }
    int res = x + y;
    if (q >= m / 2) {
        res++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int m;
        cin >> m;
        vector<int> p(m);
        for (int i = 0; i < m; i++) {
            cin >> p[i];
            p[i]--;
        }
        cout << Solve(p) << '\n';
    }
    return 0;
}