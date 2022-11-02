#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

struct Point {
    int idx, x;
    char c;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<Point>> pps(2);
    {
        vector<Point> ps(n);
        for (int i = 0; i < n; ++i) ps[i].idx = i;
        for (auto& p : ps) cin >> p.x;
        for (auto& p : ps) cin >> p.c;

        for (auto p : ps) {
            pps[p.x % 2].push_back(p);
        }
    }

    vector<int> ans(n, -1);
    for (auto& ps : pps) {
        sort(ps.begin(), ps.end(),
             [](auto p, auto q) { return p.x < q.x; });

        // RL
        {
            vector<Point> nps;
            for (const auto& p : ps) {
                if (!nps.empty() &&
                    nps.back().c == 'R' &&
                    p.c == 'L') {
                    auto pp = nps.back();
                    nps.pop_back();

                    auto t = (p.x - pp.x) / 2;
                    ans[pp.idx] = ans[p.idx] = t;
                } else {
                    nps.push_back(p);
                }
            }
            swap(ps, nps);
        }

        // LL
        {
            int l = 0;
            while (l + 1 < (int)ps.size() &&
                   ps[l].c == 'L' &&
                   ps[l + 1].c == 'L') {
                auto pp = ps[l], p = ps[l + 1];
                l += 2;

                auto t = (pp.x + p.x) / 2;
                ans[pp.idx] = ans[p.idx] = t;
            }

            ps.erase(ps.begin(), ps.begin() + l);
        }

        // RR
        {
            reverse(ps.begin(), ps.end());
            int l = 0;
            while (l + 1 < (int)ps.size() &&
                   ps[l].c == 'R' &&
                   ps[l + 1].c == 'R') {
                auto pp = ps[l], p = ps[l + 1];
                l += 2;

                auto t = m - (pp.x + p.x) / 2;
                ans[pp.idx] = ans[p.idx] = t;
            }

            ps.erase(ps.begin(), ps.begin() + l);
            reverse(ps.begin(), ps.end());
        }

        // LR
        if (ps.size() >= 2) {
            assert(ps.size() == 2);

            auto pp = ps[0], p = ps[1];
            assert(pp.c == 'L' && p.c == 'R');

            auto t = m - (p.x - pp.x) / 2;
            ans[pp.idx] = ans[p.idx] = t;
        }

        // 
    }

    for (auto t : ans) cout << t << " ";
    cout << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}