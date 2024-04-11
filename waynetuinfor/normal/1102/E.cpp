#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn], l[maxn], r[maxn];

int main() {
    int n; scanf("%d", &n);
    vector<int> ds;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ds.push_back(a[i]);
    }
    sort(ds.begin(), ds.end());
    ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 0; i < n; ++i) 
        a[i] = lower_bound(ds.begin(), ds.end(), a[i]) - ds.begin();
    for (int i = 0; i < n; ++i) {
        l[i] = n;
        r[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) s.insert(make_pair(l[i], i));
    int ans = 0;
    for (int i = 0; i < n; ) {
        ++ans;
        int bound = r[a[i]];
        while (s.size() && s.begin()->first <= bound) {
            bound = max(bound, r[s.begin()->second]);
            s.erase(s.begin());
        }
        if (s.size()) i = s.begin()->first;
        else i = n;
    }
    int res = 1;
    for (int i = 0; i < ans - 1; ++i) res = res * 2 % 998244353;
    printf("%d\n", res);
    return 0;
}