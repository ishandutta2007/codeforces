#include <bits/stdc++.h>
using namespace std;

const int kN = 1000 + 5;
const int kInf = 1'000'000;
int x[kN], y[kN], z[kN];

void Print(const vector<int> &v) {
    printf("%d\n", (int)v.size());
    for (int u : v) printf("%d ", u + 1);
    puts("");
    exit(0);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
    while (true) {
        vector<int> v[2][2];
        for (int i = 0; i < n; ++i) {
            int a = x[i] % 2 != 0;
            int b = y[i] % 2 != 0;
            v[a][b].push_back(i);
        }
        bool ok = true;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (v[i][j].size() == n) ok = false;
            }
        }
        if (ok) break;
        for (int i = 0; i < n; ++i) {
            if (x[i] % 2 == 0) x[i] /= 2;
            else x[i] = (x[i] - 1) / 2;
            if (y[i] % 2 == 0) y[i] /= 2;
            else y[i] = (y[i] - 1) / 2;
        }
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        if ((x[i] + y[i]) % 2 != 0) v.push_back(i);
    }
    if (!v.empty() && v.size() < n) Print(v);
    v.clear();
    for (int i = 0; i < n; ++i) {
        if (x[i] % 2 != 0) v.push_back(i);
    }
    assert(!v.empty() && v.size() < n);
    Print(v);
    assert(false);
    return 0;
}