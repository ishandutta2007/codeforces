#include <bits/stdc++.h>
using namespace std;

struct Data {
    int64_t sum;
    int l, r, len;

    bool Merge(const Data &rhs) {
        int64_t s = sum + rhs.sum;
        if (s * rhs.len > rhs.sum * (len + rhs.len)) return false;
        sum += rhs.sum;
        len += rhs.len;
        l = rhs.l;
        return true;
    }
};

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    vector<Data> stk;
    for (int i = 0; i < n; ++i) {
        Data d{a[i], i, i, 1};
        while (!stk.empty() && d.Merge(stk.back())) stk.pop_back();
        stk.push_back(d);
    }
    vector<double> ans(n);
    for (auto d : stk) {
        for (int i = d.l; i <= d.r; ++i) ans[i] = 1.0 * d.sum / d.len;
    }
    for (int i = 0; i < n; ++i) printf("%.20lf\n", ans[i]);
    return 0;
}