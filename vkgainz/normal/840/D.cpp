#include <bits/stdc++.h>
using namespace std;
 
vector<int> a;

struct query {
    int l, r, k, idx;
};
vector<query> in;
vector<int> ret;

void ins(pair<int, int> x, vector<pair<int, int>> &y) {
    int sz = 5;
    int in = -1;
    for (int i = 0; i < sz; i++)
        if (y[i].first == x.first)
            in = i;
    if (in >= 0) {
        y[in] = x;
    }
    else {
        if (x.second > y.back().second) {
            y.pop_back();
            y.push_back(x);
        }
    }
    for (int i = sz - 1; i >= 1; i--)
        if (y[i].second > y[i - 1].second)
            swap(y[i], y[i - 1]);
}

int n, q;
vector<vector<int>> pos(n);
vector<int> f;

int freq(int x, int l, int r) {
    auto a = upper_bound(pos[x].begin(), pos[x].end(), r) - pos[x].begin() - 1;
    auto b = lower_bound(pos[x].begin(), pos[x].end(), l) - pos[x].begin();
    return a - b + 1;
}

void solve(int l, int r, vector<query> &curr) {
    if (l == r) {
        for(auto [l, r, k, idx] : curr) {
            ret[idx] = a[l];
        }
        return;
    }

    int m = (l + r) / 2;
    vector<vector<pair<int, int>>> bstL(m - l + 1, vector<pair<int, int>>(5));
    vector<vector<pair<int, int>>> bstR(r - m, vector<pair<int, int>>(5));
    for(int i = m; i >= l; i--) {
        ++f[a[i]];
        if (i < m)
            for(int j = 0; j < 5; j++)
                bstL[m - i][j] = bstL[m - i - 1][j];
        ins({a[i], f[a[i]]}, bstL[m - i]);
    }
    for (int i = m; i >= l; i--) --f[a[i]];
    for (int i = m + 1; i <= r; i++) {
        ++f[a[i]];
        if (i > m + 1)
            for (int j = 0; j < 5; j++)
                bstR[i - (m + 1)][j] = bstR[i - (m + 2)][j];
        ins({a[i], f[a[i]]}, bstR[i - (m + 1)]);
    }
    for (int i = m + 1; i <= r; i++) --f[a[i]];

    vector<query> left, right;
    for(auto [lf, rf, k, idx] : curr) {
        if (lf <= m && rf > m) {
            int ans = 1e9;
            for (auto [a, b] : bstL[m - lf]) {
                int occ = freq(a, lf, rf);
                if (occ >= (rf - lf + 1 + k) / k)
                    ans = min(ans, a);
            }
            for (auto [a, b] : bstR[rf - (m + 1)]) {
                int occ = freq(a, lf, rf);
                if (occ >= (rf - lf + 1 + k) / k)
                    ans = min(ans, a);
            }
            ret[idx] = ans;
        }
        else if (rf <= m)
            left.push_back({lf, rf, k, idx});
        else
            right.push_back({lf, rf, k, idx});
    }
    solve(l, m, left), solve(m + 1, r, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    a.resize(n), in.resize(q), ret.resize(q), pos.resize(n), f.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        pos[a[i]].push_back(i);
    }
    for(int i = 0; i < q; i++) {
        cin >> in[i].l >> in[i].r >> in[i].k;
        --in[i].l, --in[i].r;
        in[i].idx = i;
    }
    solve(0, n - 1, in);
    for (int i = 0; i < q; i++) {
        if(ret[i] == 1e9) cout << -1 << "\n";
        else cout << ret[i] + 1 << "\n";
    }
}