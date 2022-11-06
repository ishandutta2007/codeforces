#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int g[maxn], v[maxn], last[maxn];
int ans[maxn], n, k, m, a;

bool check3(int x) {
    vector<int> vg(g, g + maxn), vv(v, v + maxn), vlast(last, last + maxn);
    vv[x] += m - a;
    if (m - a > 0) vlast[x] = m;
    if (vv[x] == 0) return false;
    int w = 0;
    for (int i = 1; i <= n; ++i) if (i != x) {
        if (vv[i] > vv[x] || vv[i] == vv[x] && vlast[i] < vlast[x]) ++w;
    }
    return w < k;
}

bool check1(int x) {
    vector<int> vg(g, g + maxn), vv(v, v + maxn), vlast(last, last + maxn);
    vector<int> cand;
    int w = 0;
    for (int i = 1; i <= n; ++i) if (i != x) {
        if (vv[i] < vv[x] || vv[i] == vv[x] && vlast[i] > vlast[x]) cand.push_back(i);
        else ++w;
    }
    sort(cand.begin(), cand.end(), [&](const int &i, const int &j) { return vv[i] > vv[j]; });
    int r = m - a;
    for (int i = 0; i < cand.size(); ++i) {
        int z = vv[x] + 1 - vv[cand[i]];
        // printf("z = %d\n", z);
        if (r < z) break;
        r -= z;
        ++w;
    }
    // printf("w = %d\n", w);
    return w < k;
}

int main() {
    scanf("%d %d %d %d", &n, &k, &m, &a);
    for (int i = 1; i <= a; ++i) {
        scanf("%d", g + i);
        ++v[g[i]]; last[g[i]] = i;
    }
    for (int i = 1; i <= n; ++i) if (!check3(i)) ans[i] = 3;
    for (int i = 1; i <= n; ++i) if (!ans[i]) {
        if (v[i] == 0) ans[i] = 2;
    }
    for (int i = 1; i <= n; ++i) if (!ans[i]) {
        int w = 0;
        for (int j = 1; j <= n; ++j) if (i != j) {
            if (v[i] < v[j] || v[i] == v[j] && last[i] > last[j]) ++w;
        }
        if (w >= k) ans[i] = 2;
    } 
    for (int i = 1; i <= n; ++i) if (!ans[i]) {
        if (check1(i)) ans[i] = 1;
        else ans[i] = 2;
    }
    for (int i = 1; i <= n; ++i) printf("%d ", ans[i]); puts("");
    return 0;
}