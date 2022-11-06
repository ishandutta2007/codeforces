#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void dfs(long long k) {
    if (k > 1000000000) return;
    v.push_back(k);
    dfs(k * 10 + 4), dfs(k * 10 + 7);
}

long long calc(int l, int r, int a, int b) {
    if (a > r || l > b) return 0;
    if (l <= a && r >= b) return b - a + 1;
    if (a <= l && b >= r) return r - l + 1;
    if (b >= r) return r - a + 1;
    else return b - l + 1;
}

int main() {
    dfs(4), dfs(7);
    sort(v.begin(), v.end());
    int pl, pr, vl, vr, k; scanf("%d %d %d %d %d", &pl, &pr, &vl, &vr, &k);
    long long q = (pr - pl + 1) * 1ll * (vr - vl + 1);
    long long p = 0;
    for (int i = 0, j = i + k - 1; j < v.size(); ++i, ++j) {
        int l = (i == 0 ? 1 : v[i - 1] + 1), r = (j == v.size() - 1 ? 1000000000 : v[j+ 1] - 1);
        p += calc(l, v[i], vl, vr) * calc(v[j], r, pl, pr);
        p += calc(l, v[i], pl, pr) * calc(v[j], r, vl, vr);
        if (k == 1 && v[i] >= vl && v[i] <= vr && v[i] >= pl && v[i] <= pr) --p;
    }
    printf("%.20lf\n", 1.0 * p / q);
    return 0;
}