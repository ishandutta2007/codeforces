#include <bits/stdc++.h>
using namespace std;

int x[10], y[10];

long long dot(pair<int, int> a, pair<int, int> b) { return a.first * b.first + a.second * b.second; }
long long len(pair<int, int> a) { return a.first * a.first + a.second * a.second; }

bool check1(vector<int> v) {
    pair<int, int> now = { x[v[1]] - x[v[0]], y[v[1]] - y[v[0]] };
    for (int i = 1; i < 4; ++i) {
        int to = i + 1;
        if (to >= 4) to -= 4;
        pair<int, int> np = { x[v[to]] - x[v[i]], y[v[to]] - y[v[i]] };
        if (dot(np, now) != 0 || len(now) != len(np)) return false;
        now = np;
    }
    if (len(now) == 0) return false;
    return true;
}

bool check2(vector<int> v) {
    pair<int, int> v1 = { x[v[1]] - x[v[0]], y[v[1]] - y[v[0]] };
    pair<int, int> v2 = { x[v[2]] - x[v[1]], y[v[2]] - y[v[1]] };
    pair<int, int> v3 = { x[v[3]] - x[v[2]], y[v[3]] - y[v[2]] };
    pair<int, int> v4 = { x[v[0]] - x[v[3]], y[v[0]] - y[v[3]] };
    if (dot(v1, v2) != 0 || dot(v2, v3) != 0 || dot(v3, v4) != 0 || dot(v4, v1) != 0) return false;
    if (len(v1) != len(v3) || len(v2) != len(v4) || len(v1) == 0 || len(v2) == 0) return false;
    return true;
}

int main() {
    for (int i = 0; i < 8; ++i) cin >> x[i] >> y[i];
    vector<int> o(8); iota(o.begin(), o.end(), 0);
    do {
        if (check1({ o[0], o[1], o[2], o[3] }) && check2({ o[4], o[5], o[6], o[7] })) {
            cout << "YES" << endl;
            for (int i = 0; i < 4; ++i) cout << o[i] + 1 << ' '; cout << endl;
            for (int i = 4; i < 8; ++i) cout << o[i] + 1 << ' '; cout << endl;
            return 0;
        }
    } while (next_permutation(o.begin(), o.end()));
    cout << "NO" << endl;
    return 0;
}