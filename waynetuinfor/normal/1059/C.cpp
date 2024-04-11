#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

void brute(int n) {
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    vector<int> ans(n, 1);
    do {
        vector<int> r;
        for (int i = 0; i < n; ++i) {
            int g = 0;
            for (int j = i; j < n; ++j) g = __gcd(g, v[j]);
            r.push_back(g);
        }
        ans = max(ans, r);
    } while (next_permutation(v.begin(), v.end()));
    for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
    puts("");
}

void solve(int n, int prod) {
    if (n == 1) {
        printf("%d ", prod);
        return;
    }
    if (n == 2) {
        printf("%d %d ", prod, prod * 2);
        return;
    }
    if (n == 3) {
        printf("%d %d %d ", prod, prod, prod * 3);
        return;
    }
    int m = (n + 1) >> 1;
    for (int i = 1; i <= m; ++i) printf("%d ", prod);
    solve(n - m, prod * 2);
}

int main() {
    int n; scanf("%d", &n);
    solve(n, 1);
}