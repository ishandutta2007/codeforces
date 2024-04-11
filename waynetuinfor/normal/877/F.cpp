#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn = 1e5 + 10;
int n, k;
int s[maxn], t[maxn], ans[maxn], cur, pre[3][maxn], cnt[maxn << 2];

struct query {
    int l, r, block, id;
    bool operator<(const query &rhs) const {
        return block == rhs.block ? r < rhs.r : block > rhs.block;
    }
};

void add(int now, int ptr) {
    // cout << "add now = " << now << " ptr = " << ptr << endl;
    cur += cnt[pre[ptr][now]];
    ++cnt[pre[0][now]];
}

void sub(int now, int ptr) {
    // cout << "sub now = " << now << " ptr = " << ptr << endl;
    --cnt[pre[0][now]];
    cur -= cnt[pre[ptr][now]];
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> t[i];
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1];
        int a; cin >> a;
        s[i] += (t[i] == 1 ? 1 : -1) * a;
        v.push_back(s[i]); v.push_back(s[i] - k); v.push_back(s[i] + k);
    }
    v.push_back(-k); v.push_back(k);
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 0; i <= n; ++i) {
        pre[0][i] = lower_bound(v.begin(), v.end(), s[i]) - v.begin();
        pre[1][i] = lower_bound(v.begin(), v.end(), s[i] - k) - v.begin();
        pre[2][i] = lower_bound(v.begin(), v.end(), s[i] + k) - v.begin();
    }
    int q; cin >> q;
    int sz = 1 + (int)sqrt(n);
    vector<query> qry;
    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r; --l;
        qry.push_back((query){ l, r, l / sz, i });
    }
    sort(qry.begin(), qry.end());
    for (int i = 0, l = 1, r = 0; i < q; ++i) {
        // cout << "query l = " << qry[i].l << " r = " << qry[i].r << endl;
        while (r < qry[i].r) add(++r, 1);
        while (r > qry[i].r) sub(r--, 1);
        while (l < qry[i].l) sub(l++, 2);
        while (l > qry[i].l) add(--l, 2);
        ans[qry[i].id] = cur;
    }
    for (int i = 0; i < q; ++i) cout << ans[i] << endl;
    return 0;
}