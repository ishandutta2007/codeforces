#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int x[maxn], y[maxn];
int a[maxn], b[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
    for (int i = 0; i < n; ++i) scanf("%d%d", &a[i], &b[i]);
    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ++cnt[make_pair(x[i] + a[j], y[i] + b[j])];
        }
    }
    for (auto it : cnt) {
        if (it.second == n) {
            printf("%d %d\n", it.first, it.second);
            return 0;
        }
    }
    assert(false);
}