#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int p[N], pos[N], ans[N];
vector<int> divs[N];
vector<pair<int, int>> Q[N];
int fenw[N];

void Add(int x) {
    x++;
    for (; x > 0; x -= x & -x) {
        fenw[x] += 1;
    }
}

int Get(int x) {
    x++;
    int res = 0;
    for (; x < N; x += x & -x) {
        res += fenw[x];
    }
    return res;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        pos[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            int x = pos[i], y = pos[j];
            if (x > y) {
                swap(x, y);
            }
            divs[y].push_back(x);
        }
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        Q[r].push_back({l, i});
    }
    for (int i = 1; i <= n; i++) {
        for (int j : divs[i]) {
            Add(j);
        }
        for (auto j : Q[i]) {
            ans[j.second] = Get(j.first);
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%i\n", ans[i]);
    }
    return 0;
}