#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

using namespace std;

void fail() {
    cout << "-1\n";
    exit(0);
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> ps(n);
    vector<int> pos(n * 2);
    for (int i = 0; i < n; ++i) {
        auto& [x, y] = ps[i];
        cin >> x >> y;
        pos[--x] = i;
        pos[--y] = i;
    }

    vector<bool> used(n, false);
    int ans = 0;

    int l = 0, r = n * 2 - 1;
    // put numbers in [l, r]
    while (l <= r) {
        if (pos[l] == pos[r]) {
            ++l, --r;
            continue;
        }

        int cost = 0, num = 0;
        int fl, fr, bl, br;
        {
            auto i = pos[l];
            used[i] = true;
            ++num;

            // l
            if (ps[i].first != l) {
                ++cost;
                swap(ps[i].first, ps[i].second);
            }
            fl = l, br = ps[i].second;
        }
        {
            auto i = pos[r];
            used[i] = true;
            ++num;

            // r
            if (ps[i].first != r) {
                ++cost;
                swap(ps[i].first, ps[i].second);
            }
            fr = r, bl = ps[i].second;
        }

        if (bl > br) fail();

        while (fl != bl || fr != br) {
            if (fl > fr || bl > br) fail();

            while (fl < bl) {
                ++fl;
                if (used[pos[fl]]) continue;
                ++num;

                // fl
                auto i = pos[fl];
                used[i] = true;

                // fl
                if (ps[i].first != fl) {
                    ++cost;
                    swap(ps[i].first, ps[i].second);
                }

                // 
                if (ps[i].second > br) fail();
                br = ps[i].second;
            }

            while (bl < fl) {
                ++bl;
                if (used[pos[bl]]) continue;
                ++num;

                // bl
                auto i = pos[bl];
                used[i] = true;

                // bl
                if (ps[i].second != bl) {
                    ++cost;
                    swap(ps[i].first, ps[i].second);
                }

                // 
                if (ps[i].first > fr) fail();
                fr = ps[i].first;
            }

            while (fr > br) {
                --fr;
                if (used[pos[fr]]) continue;
                ++num;

                // fr
                auto i = pos[fr];
                used[i] = true;

                // fr
                if (ps[i].first != fr) {
                    ++cost;
                    swap(ps[i].first, ps[i].second);
                }

                // 
                if (ps[i].second < bl) fail();
                bl = ps[i].second;
            }

            while (br > fr) {
                --br;
                if (used[pos[br]]) continue;
                ++num;

                // br
                auto i = pos[br];
                used[i] = true;

                // br
                if (ps[i].second != br) {
                    ++cost;
                    swap(ps[i].first, ps[i].second);
                }

                // 
                if (ps[i].first < fl) fail();
                fl = ps[i].first;
            }
        }

        if (fl > fr || bl > br) fail();

        ans += min(cost, num - cost);
        l = fl + 1, r = fr - 1;
    }

    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}