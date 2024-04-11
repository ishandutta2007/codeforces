#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
long long w[maxn][maxn], d[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; i + j < n; ++j) cin >> w[i][i + j], w[i + j][i] = w[i][i + j];
    }
    long long Min = LLONG_MAX;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        if (i != j) Min = min(Min, w[i][j]);
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        if (i != j) w[i][j] -= Min;
    }
    fill(d, d + maxn, LLONG_MAX);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        if (i != j) d[i] = min(d[i], 2 * w[i][j]);
    }
    for (int _ = 0; _ < n; ++_) {
        long long w_min = LLONG_MAX, vtx = -1;
        for (int i = 0; i < n; ++i) {
            if (!v[i]) if (d[i] < w_min) w_min = d[i], vtx = i;
        }
        v[vtx] = true;
        for (int i = 0; i < n; ++i) {
            if (!v[i]) d[i] = min(d[i], d[vtx] + w[vtx][i]);
        }
    } 
    for (int i = 0; i < n; ++i) cout << d[i] + Min * (long long)(n - 1) << '\n';
    return 0;
}