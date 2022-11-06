#include <bits/stdc++.h>
using namespace std;

const int kN = 200'000 + 5;
int f[kN], g[kN];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &f[i]);
        f[i]--;
    }
    for (int i = 0; i < n; ++i) {
        if (f[i] != -1) g[f[i]] = 1;
    }
    vector<int> x, y, z;
    for (int i = 0; i < n; ++i) {
        if (f[i] == -1 && g[i] == 0) z.push_back(i);
        else if (f[i] == -1) x.push_back(i);
        else if (g[i] == 0) y.push_back(i);
    }
    if (z.size() > 1) {
        for (int i = 0; i < z.size(); ++i) f[z[i]] = z[(i + 1) % z.size()];
        for (int i = 0; i < x.size(); ++i) f[x[i]] = y[i];
    } else {
        if (!z.empty()) {
            x.push_back(z[0]);
            y.push_back(z[0]);
        }
        reverse(y.begin(), y.end());
        for (int i = 0; i < x.size(); ++i) f[x[i]] = y[i];
    }
    for (int i = 0; i < n; ++i) printf("%d ", f[i] + 1);
}