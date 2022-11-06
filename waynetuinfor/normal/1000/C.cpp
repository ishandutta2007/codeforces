#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5;
long long l[maxn], r[maxn], ans[maxn];
int tl[maxn], tr[maxn], s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<long long> ds;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        ds.push_back(l[i]), ds.push_back(r[i]);
        ds.push_back(l[i] - 1), ds.push_back(l[i] + 1);
        ds.push_back(r[i] - 1), ds.push_back(r[i] + 1);
    }
    sort(ds.begin(), ds.end()), ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 0; i < n; ++i) {
        tl[i] = lower_bound(ds.begin(), ds.end(), l[i]) - ds.begin() ;
        tr[i] = lower_bound(ds.begin(), ds.end(), r[i]) - ds.begin() ;
    }
    for (int i = 0; i < n; ++i) ++s[tl[i]], --s[tr[i] + 1];
    for (int i = 1; i < maxn; ++i) s[i] += s[i - 1];
    for (int i = 0; i < ds.size() - 1; ++i) {
        long long nxt = ds[i + 1] - 1;
        ans[s[i]] += nxt - ds[i] + 1;
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}