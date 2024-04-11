#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
pair<pair<int, int>, int> p[maxn];
int ans[maxn];

struct SegmentTree {
#define M ((L + R) >> 1) 
    SegmentTree *lc, *rc;
    int sum;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        sum = 0;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    void pull() {
        sum = lc->sum + rc->sum;
    }
    void add(int L, int R, int x) {
        if (L == R) { ++sum; return; }
        if (x <= M) lc->add(L, M, x);
        else rc->add(M + 1, R, x);
        pull();
    }
    int query(int L, int R, int l, int r) {
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return sum;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
#undef M
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first.first >> p[i].first.second;
        p[i].second = i;
        v.push_back(p[i].first.first); v.push_back(p[i].first.second);
    }
    sort(p, p + n, [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) { return a.first.second < b.first.second; });
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    st = new SegmentTree(0, v.size() - 1);
    for (int i = 1; i < n; ++i) {
        int pos = lower_bound(v.begin(), v.end(), p[i - 1].first.first) - v.begin();
        st->add(0, v.size() - 1, pos);
        int l = lower_bound(v.begin(), v.end(), p[i].first.first) - v.begin(), r = lower_bound(v.begin(), v.end(), p[i].first.second) - v.begin();
        ans[p[i].second] = st->query(0, v.size() - 1, l, r);
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << endl;
    return 0;
}