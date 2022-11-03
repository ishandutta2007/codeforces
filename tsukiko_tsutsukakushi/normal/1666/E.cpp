#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, n;
    cin >> l >> n;

    vector<int> a(n);
    for (auto& e : a) cin >> e;

    int fr;
    {
        auto f = [&](int x) {
            int cx = 0;
            for (int v : a) {
                if (v < cx) return false;
                cx = max(v, cx + x);
            }
            return cx <= l;
        };
        int s = 0, t = l + 1;
        while (t - s > 1) {
            int x = (s + t) >> 1;
            (f(x) ? s : t) = x;
        }
        fr = s;
    }
    int to;
    {
        auto f = [&](int r) {
            int min_x = 0, max_x = 0;
            for (int v : a) {
                max_x = min(max_x, v);
                if (max_x < min_x) return false;
                if (max_x + r < v) return false;
                min_x = max(min_x + fr, v);
                max_x = max_x + r;
            }
            return min_x <= l and l <= max_x;
        };
        int s = fr - 1, t = l;
        while (t - s > 1) {
            int x = (s + t) >> 1;
            (f(x) ? t : s) = x;
        }
        to = t;
    }

    vector<pair<int, int>> ranges;
    int min_x = 0, max_x = 0;
    for (int v : a) {
        ranges.emplace_back(min_x, max_x);
        max_x = min(max_x, v);
        if (max_x < min_x) return false;
        if (max_x + to < v) return false;
        min_x = max(min_x + fr, v);
        max_x = max_x + to;
    }

    vector<pair<int, int>> ans;

    int r = l;
    for (auto it = ranges.rbegin(); it != ranges.rend(); ++it) {
        auto [s, t] = *it;
        int back = min(r - s, to);
        ans.emplace_back(r - back, r);
        r -= back;
    }
    reverse(ans.begin(), ans.end());

    for (auto &[l, r] : ans) {
        cout << l << ' ' << r << '\n';
    }
    return 0;
}