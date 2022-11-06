#include <bits/stdc++.h>
using namespace std;

const int kN = 1000'000 + 5;
const int kInf = 2'000'000'000;
int x[kN], y[kN], l[kN], r[kN], tl[kN], tr[kN];
int fw1[kN], fw2[kN];

void Modify(int p, int l, int r) {
    for (int i = p + 1; i < kN; i += i & -i) {
        fw1[i] = min(fw1[i], r);
        fw2[i] = max(fw2[i], l);
    }
}

bool Query(int p, int l, int r) {
    for (int i = p + 1; i > 0; i -= i & -i) {
        if (fw1[i] < l) return true;
        if (fw2[i] > r) return true;
    }
    return false;
}

void Init() {
    for (int i = 0; i < kN; ++i) {
        fw1[i] = kInf;
        fw2[i] = -kInf;
    }
}

void Solve(int n) {
    Init();
    vector<int> ds;
    for (int i = 0; i < n; ++i) {
        ds.push_back(x[i]);
        ds.push_back(y[i]);
    }
    sort(ds.begin(), ds.end());
    ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 0; i < n; ++i) {
        tl[i] = lower_bound(ds.begin(), ds.end(), x[i]) - ds.begin();
        tr[i] = lower_bound(ds.begin(), ds.end(), y[i]) - ds.begin();
    }
    vector<int> od(n);
    iota(od.begin(), od.end(), 0);
    sort(od.begin(), od.end(), [&](int i, int j) {
        return x[i] > x[j];
    });
    for (int i = 0, j = 0; i < n; ++i) {
        // printf("od[i] = %d\n", od[i]);
        while (j < n && x[od[j]] >= x[od[i]]) {
            // printf("od[j] = %d\n", od[j]);
            // printf("Add %d %d\n", tl[od[j]], l[od[j]]);
            // printf("Add %d %d\n", tl[od[j]], r[od[j]]);
            Modify(tl[od[j]], l[od[j]], r[od[j]]);
            ++j;
        }
        // printf("Query %d %d %d\n", tr[od[i]], l[od[i]], r[od[i]]);
        if (Query(tr[od[i]], l[od[i]], r[od[i]])) {
            puts("NO");
            exit(0);
        }
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d%d%d", &x[i], &y[i], &l[i], &r[i]);
    Solve(n);
    for (int i = 0; i < n; ++i) {
        swap(x[i], l[i]);
        swap(y[i], r[i]);
    }
    Solve(n);
    puts("YES");
    return 0;
}