#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

struct dish {
    int a, b, m, idx;
};

struct interval {
    int l, r, idx;
};

bool cmpd(dish &x, dish &y) {
    return x.m < y.m;
}

bool cmpi(interval &x, interval &y) {
    if (x.r == y.r) {
        return x.l < y.l;
    } else {
        return x.r < y.r;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<dish> in(n);
        vector<dish> orig(n);
        for (int i = 0; i < n; i++) {
            cin >> in[i].a >> in[i].b;
            int m; cin >> m;
            in[i].m = in[i].a + in[i].b - m;
            in[i].idx = i;
            orig[i] = {in[i].a, in[i].b, in[i].m, in[i].idx};
        }
        sort(in.begin(), in.end(), cmpd);
        int st = 0;
        int mn = 0;
        vector<pair<int, int>> ans(n);
        for (int i = 0; i <= n; i++) {
            if (i == n || in[i].m != in[st].m) {
                vector<dish> tmp;
                for (int j = st; j < i; j++) {
                    tmp.push_back(in[j]);
                }
                vector<interval> use;
                for (dish iter : tmp) {
                    int lo = max(iter.m - iter.b, 0), hi = min(iter.a, iter.m);
                    use.push_back({lo, hi, iter.idx});
                }
                sort(use.begin(), use.end(), cmpi);
                int k = 0;
                for (int j = 0; j < use.size(); j++) {
                    ++mn;
                    while (k < use.size() && use[k].l <= use[j].r) {
                        ans[use[k].idx] = {use[j].r, in[st].m - use[j].r};
                        ++k;
                    }
                    j = k - 1;
                }
                st = i;
            }
        }
        cout << mn << "\n";
        for (int i = 0; i < n; i++) {
            cout << (orig[i].a - ans[i].first) << " " << (orig[i].b - ans[i].second) << "\n";
        }
    }
}