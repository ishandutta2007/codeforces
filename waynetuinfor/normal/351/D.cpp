#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], l[maxn], r[maxn], b[maxn];
int ans[maxn], diff[maxn], dist;
int eq[maxn], offset;
deque<int> pos[maxn], dt[maxn];

void push(int x) {
    int y = a[x];
    dist += (int)pos[y].size() == 0;
    if (pos[y].size()) {
        if (x > pos[y].back()) {
            int d = x - pos[y].back();
            if (dt[y].size()) diff[y] += dt[y].back() != d;
            dt[y].push_back(d);
            pos[y].push_back(x);
        } else {
            int d = pos[y].front() - x;
            if (dt[y].size()) diff[y] += dt[y].front() != d;
            dt[y].push_front(d);
            pos[y].push_front(x);
        }
    } else {
        pos[y].push_back(x);
    }
    int c = dt[y].size() == 0 || diff[y] == 0;
    if (eq[y] != c) {
        eq[y] = c;
        if (c) ++offset;
        else --offset;
    } 
}

void pull(int x) {
    int y = a[x];
    if (x == pos[y].back()) {
        pos[y].pop_back();
        if (pos[y].size()) {
            int d = x - pos[y].back();
            dt[y].pop_back();
            if (dt[y].size()) diff[y] -= d != dt[y].back();
        }
    } else {
        pos[y].pop_front();
        if (pos[y].size()) {
            int d = pos[y].front() - x;
            dt[y].pop_front();
            if (dt[y].size()) diff[y] -= d != dt[y].front();
        }
    }
    dist -= (int)pos[y].size() == 0;
    int c = (int)pos[y].size() > 0 && (dt[y].size() == 0 || diff[y] == 0);
    if (eq[y] != c) {
        eq[y] = c;
        if (c) ++offset;
        else --offset;
    } 
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int size = (int)sqrt(n) + 1;
    int q; scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        --l[i], --r[i];
        b[i] = l[i] / size;
    }
    vector<int> v(q);
    iota(v.begin(), v.end(), 0);
    sort(v.begin(), v.end(), [&](int i, int j) {
        if (b[i] == b[j]) return r[i] < r[j];
        return b[i] < b[j];
    });
    int tl = 0, tr = -1;
    for (int i = 0; i < q; ++i) {
        int j = v[i];
        while (tr < r[j]) push(++tr);
        while (tr > r[j]) pull(tr--);
        while (tl > l[j]) push(--tl);
        while (tl < l[j]) pull(tl++);
        ans[j] = dist + (offset == 0);
    }
    for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
    return 0;
}