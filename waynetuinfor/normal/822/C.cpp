#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, inf = 2e9 + 10;

struct Voucher {
    int l, r, c, d, id;
    bool operator<(const Voucher& rhs) const {
        return c < rhs.c;
    }
} vo[maxn];

vector<Voucher> dur[maxn]; 
vector<pair<pair<int, int>, int>> lans[maxn], rans[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x; cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> vo[i].l >> vo[i].r >> vo[i].c, vo[i].d = vo[i].r - vo[i].l + 1, vo[i].id = i;
    for (int i = 0; i < n; ++i) if (vo[i].d >= 0 && vo[i].d < maxn) dur[vo[i].d].push_back(vo[i]);
    for (int i = 0; i < maxn; ++i) if (dur[i].size()) {
        sort(dur[i].begin(), dur[i].end(), [](const Voucher& a, const Voucher& b) {
            return a.l > b.l;
        });
        for (auto j : dur[i]) lans[i].push_back(make_pair(make_pair(j.l, j.id), inf));
        lans[i][0].second = vo[lans[i][0].first.second].c;
        for (int j = 1; j < lans[i].size(); ++j) lans[i][j].second = min(lans[i][j - 1].second, vo[lans[i][j].first.second].c);
        sort(dur[i].begin(), dur[i].end(), [](const Voucher& a, const Voucher& b) {
            return a.r < b.r;
        });
        for (auto j : dur[i]) rans[i].push_back(make_pair(make_pair(j.r, j.id), inf));
        rans[i][0].second = vo[rans[i][0].first.second].c;
        for (int j = 1; j < rans[i].size(); ++j) rans[i][j].second = min(rans[i][j - 1].second, vo[rans[i][j].first.second].c);
    } 
    int ans = inf;
    for (int i = 0; i < n; ++i) if (x - vo[i].d >= 0) {
        int t = x - vo[i].d;
        if (lans[t].size() == 0) continue;
        int d = 1, pos = 0; while (d <= lans[t].size()) d <<= 1;
        while (d >>= 1) if (pos + d < lans[t].size()) if (lans[t][pos + d].first.first > vo[i].r) pos += d;
        if (lans[t][0].first.first > vo[i].r) ans = min(ans, vo[i].c + lans[t][pos].second);
        d = 1; pos = 0;
        while (d <= rans[t].size()) d <<= 1;
        while (d >>= 1) if (pos + d < rans[t].size()) if (rans[t][pos + d].first.first < vo[i].l) pos += d;
        if (rans[t][0].first.first < vo[i].l) ans = min(ans, vo[i].c + rans[t][pos].second);
    }
    if (ans == inf) ans = -1;
    cout<< ans << endl;
    return 0;
}