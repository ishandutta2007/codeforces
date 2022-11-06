#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
char s[maxn];
int n, a[maxn], b[4];

bool check(int x) {
    for (int i = 0; i < 4; ++i) b[i] = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) ++b[a[i]];
    }
    int cnt[4] = { 0, 0, 0, 0 };
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            ++cnt[a[i]];
            --b[a[i]];
            continue;
        }
        vector<pair<int, int>> cand;
        int mc = n + 1;
        for (int j = 0; j < 4; ++j) mc = min(mc, cnt[j]);
        for (int j = 0; j < 4; ++j) if (cnt[j] == mc) cand.emplace_back(b[j], j);
        sort(cand.begin(), cand.end(), greater<pair<int, int>>());
        if (cand.size() == 1) ++cnt[cand[0].second];
        else ++cnt[cand[0].second == x ? cand[1].second : cand[0].second];
    }
    int mc = n + 1;
    for (int j = 0; j < 4; ++j) mc = min(mc, cnt[j]);
    if (cnt[x] == mc) return true;
    return false;
}

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'G') a[i] = 0;
        if (s[i] == 'R') a[i] = 1;
        if (s[i] == 'H') a[i] = 2;
        if (s[i] == 'S') a[i] = 3;
        if (s[i] == '?') a[i] = -1;
    }
    vector<vector<int>> v;
    v.push_back(vector<int>(4, 0));
    for (int i = 0; i < n; ++i) {
        vector<vector<int>> z;
        for (auto &j : v) {
            if (a[i] != -1) {
                ++j[a[i]];
                z.push_back(j);
                continue;
            }
            vector<int> cand;
            int mc = n + 1;
            for (int k = 0; k < 4; ++k) mc = min(mc, j[k]);
            for (int k = 0; k < 4; ++k) {
                if (j[k] == mc) {
                    ++j[k];
                    z.push_back(vector<int>(j.begin(), j.end()));
                    --j[k];
                }
            }
        }
        sort(z.begin(), z.end());
        z.resize(unique(z.begin(), z.end()) - z.begin());
        v = z;
    }
    int ans = 0;
    for (auto j : v) {
        int mc = n + 1;
        for (int k = 0; k < 4; ++k) mc = min(mc, j[k]);
        for (int k = 0; k < 4; ++k) {
            if (j[k] == mc) ans |= (1 << k);
        }
    }
    // for (int i = 0; i < 4; ++i) {
        // if (check(i)) ans |= (1 << i);
    // }
    if (ans >> 0 & 1) puts("Gryffindor");
    if (ans >> 2 & 1) puts("Hufflepuff");
    if (ans >> 1 & 1) puts("Ravenclaw");
    if (ans >> 3 & 1) puts("Slytherin");
    return 0;
}