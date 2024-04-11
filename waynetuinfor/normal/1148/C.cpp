#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5; 
int a[maxn], p[maxn];
vector<pair<int, int>> ans;

void oper(int x, int y) {
    ans.emplace_back(x, y);
    swap(p[a[x]], p[a[y]]);
    swap(a[x], a[y]);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
        p[a[i]] = i;
    }

    int m = n / 2;
    for (int i = 0; i < m; ++i) {
        if (p[i] < m && p[i + m] < m) {
            oper(p[i + m], n - 1);
            oper(n - 1, i);
            oper(i, i + m);
            assert(p[i] == n - 1 || p[i] < m);
            if (p[i] != n - 1) oper(p[i], n - 1);
            if (p[i] != i) oper(p[i], i);
        } else if (p[i] < m && p[i + m] >= m) {
            oper(i, p[i + m]);
            if (p[i] < m) oper(p[i], n - 1);
            oper(p[i + m], i + m);
            if (p[i] != i) oper(p[i], i);
        } else if (p[i] >= m && p[i + m] < m) {
            oper(p[i + m], n - 1);
            if (p[i + m] != i + m) {
                oper(p[i + m], i);
                oper(p[i + m], i + m);
            }
            if (p[i] < m && p[i] != i) oper(p[i], n - 1);
            if (p[i] != i) oper(i, p[i]);
        } else {
            oper(p[i + m], i);
            oper(p[i + m], i + m);
            if (p[i] != i) oper(p[i], i);
        }
    }

    for (int i = 0; i < n; ++i) assert(a[i] == i);
    assert((int)ans.size() <= 5 * n);
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); ++i) {
        int x = ans[i].first, y = ans[i].second;
        assert(2 * abs(x - y) >= n);
        printf("%d %d\n", x + 1, y + 1);
    }
    return 0;
}