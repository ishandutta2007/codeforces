#include <bits/stdc++.h>
//#define int long long

using namespace std;

struct edge{
    int v, u, w;
    edge() {}
    edge(int v, int u, int w): v(v), u(u), w(w) {}
};

const int N = 32;
vector <edge> e;

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int l, r;
    cin >> l >> r;
    cout << "YES" << endl;
    if (l == r) {
        cout << "2 1" << endl;
        cout << "1 2 " << l << endl;
        return 0;
    }
    if (r == l + 1) {
        cout << "3 3" << endl;
        cout << "1 2 1" << endl;
        cout << "1 3 " << l << endl;
        cout << "2 3 " << l << endl;
        return 0;
    }
    int k = r - l;
    int t = 31 - __builtin_clz(k);
    int n = t + 3;
    e.push_back(edge(1, 2, 1));
    for (int i = 1; i < n; i++) {
        if (i == 2)
            continue;
        for (int j = i + 1; j < n; j++) {
            if (j == 2)
                continue;
            e.push_back(edge(i, j, 1 << (t - j + 2)));
        }
    }
    int cur_val = 0;
    for (int pos = t; pos >= 0; pos--) {
        if (k & (1 << pos)) {
            if (pos != t) {
                e.push_back(edge(2, 2 + (t - pos), cur_val - 1));
            }
            cur_val += (1 << pos);
        }
        if (pos == 0) {
            e.push_back(edge(2, n, r - 1));
        }
    }
    for (int i = 1; i < n; i++) {
        if (i != 2)
            e.push_back(edge(i, n, l));
    }
    cout << n << ' ' << e.size() << endl;
    for (auto elem : e) {
        cout << elem.v << ' ' << elem.u << ' ' << elem.w << "\n";
    }
    return 0;
}