#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename T>
vector<T> lf(vector<T> a) {
    int n = a.size(), tp = 0;
    vector<T> stk(n+1), ret(n);
    auto cmp = [&](int i, int j) { return !(a[i] >= a[j]); }; // nearest >= a[i]
    for(int i = 0; i < n; ++i) {
        while(tp && cmp(stk[tp], i)) --tp;
        ret[i] = tp ? stk[tp] : -1;
        stk[++tp] = i;
    }
    return ret;
}
template <typename T>
vector<T> rf(vector<T> a) {
    int n = a.size(), tp = 0;
    vector<T> stk(n+1), ret(n);
    auto cmp = [&](int i, int j) { return !(a[i] >= a[j]); }; // nearest >= a[i]
    for(int i = n - 1; i >= 0; --i) {
        while(tp && cmp(stk[tp], i)) --tp;
        ret[i] = tp ? stk[tp] : n;
        stk[++tp] = i;
    }
    return ret;
}

template<typename T>
struct fenwick2 {
    vector<T> a, b;
    int n;
    fenwick2(int n): n(n), a(n), b(n) {}
    void add(int x, T v) {
        assert(0 <= x && x < n);
        for(int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v, b[i - 1] += x * v;
        }
    }
    void upd(int l, int r, T v) {
        add(l, v);
        if(r + 1 < n) add(r + 1, -v);
    }
    T qry(int x) {
        T ret = 0;
        for(int i = min(x + 1, n); i > 0; i -= i & -i) {
            ret += (x + 1) * a[i - 1] - b[i - 1];
        }
        return ret;
    }
};
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> pos(n + 1);
    for(int i = 0; i < n; ++i) cin >> a[i], pos[a[i]] = i;
    vector<int> lm = lf(a), rm = rf(a);
    vector<array<int, 3>> upd;
    vector<vector<pair<int,int>>> all(n);
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; 1ll * i * j <= n; ++j) {
            auto [l, r] = minmax({pos[i], pos[j], pos[i * j]});
            int p = pos[i * j];
            if(lm[p] >= l || rm[p] <= r) continue;
            all[p].push_back({l, -r});
        }
    }
    for(int p = 0; p < n; ++p) {
        sort(all[p].begin(), all[p].end());
        vector<pair<int,int>> b;
        for(int i = 0; i < all[p].size(); ++i) {
            all[p][i].second = -all[p][i].second;
            while(!b.empty() && b.back().second >= all[p][i].second) {
                b.pop_back();
            }
            b.push_back(all[p][i]);
        }
        int L = lm[p] + 1, R = rm[p] - 1;
        for(auto [l, r] : b) {
            // [L, l] * [r, R]
            upd.push_back({l, R, 1});
            if(L) upd.push_back({L - 1, R, -1});
            upd.push_back({l, r - 1, -1});
            if(L) upd.push_back({L - 1, r - 1, 1});
            L = l + 1;
        }
    }
    sort(upd.begin(), upd.end());
    vector<array<int, 4>> qry(q * 4);
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        qry[i] = {r, r, 1, i};
        qry[i + q] = {l - 1, r, -1, i};
        qry[i + q + q] = {r, l - 1, -1, i};
        qry[i + q + q + q] = {l - 1, l - 1, 1, i};
    }
    sort(qry.begin(), qry.end());
    vector<ll> ans(q);

    fenwick2<ll> st1(n), st2(n);
    for(auto [x, y, k] : upd) {
        st1.upd(0, y, k);
    }
    int j = 0;
    for(int i = 0; i < 4 * q; ++i) {
        while(j < upd.size() && upd[j][0] <= qry[i][0]) {
            st1.upd(0, upd[j][1], -upd[j][2]);
            st2.upd(0, upd[j][1], (upd[j][0] + 1) * upd[j][2]);
            ++j;
        }
        auto [x, y, k, qid] = qry[i];
        if(x >= 0 && y >= 0) {
            ans[qid] += k * ((x + 1) * st1.qry(y) + st2.qry(y));
        }
    }
    for(int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
}