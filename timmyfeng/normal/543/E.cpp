#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
const int B = 512;

int song[N], order[N], quality[N], lazy[B], maxi[B];

int lazy_history[B][B], maxi_history[B][B];

vector<array<int, 3>> partial[N], updates[N];
vector<array<int, 2>> whole[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> song[i];
    }

    iota(order, order + n, 0);
    sort(order, order + n, [&](int a, int b) {
        return song[a] > song[b];
    });

    for (int i = 0; i < n; ++i) {
        if (i % B == 0) {
            for (int j = 0; j <= (n - 1) / B; ++j) {
                lazy_history[i / B][j] = lazy[j];
                maxi_history[i / B][j] = maxi[j];
            }
        }

        int r = order[i], l = max(0, r - m + 1);
        if (l / B == r / B) {
            partial[i].push_back({l, r, 0});
        } else {
            if (l % B != 0) {
                int a = l - l % B + B;
                partial[i].push_back({l, a - 1, 0});
                l = a;
            }

            if (r % B != B - 1) {
                int b = r - r % B - 1;
                partial[i].push_back({b + 1, r, 0});
                r = b;
            }

            whole[i].push_back({l / B, r / B});
        }

        for (auto &[a, b, x] : partial[i]) {
            for (int j = a; j <= b; ++j) {
                maxi[j / B] = max(maxi[j / B], ++quality[j]);
            }
            x = maxi[a / B];
            updates[a / B].push_back({a % B, b % B, i});
        }

        for (auto [a, b] : whole[i]) {
            for (int j = a; j <= b; ++j) {
                ++lazy[j];
            }
        }
    }

    int s, ans = 0;
    cin >> s;

    while (s--) {
        int l, r, q;
        cin >> l >> r >> q;
        --l, --r;

        q = lower_bound(order, order + n, q ^ ans, [&](int a, int x) {
            return x <= song[a];
        }) - order;

        fill(lazy, lazy + (n - 1) / B + 1, 0);
        for (int i = 0; i <= (n - 1) / B; ++i) {
            maxi[i] = maxi_history[q / B][i];
            lazy[i] += lazy_history[q / B][i];
            lazy[i + 1] -= lazy_history[q / B][i];
        }

        for (int i = q - q % B; i < q; ++i) {
            for (auto [a, b, c] : partial[i]) {
                maxi[a / B] = c;
            }

            for (auto [a, b] : whole[i]) {
                ++lazy[a];
                --lazy[b + 1];
            }
        }

        for (int i = 1; i <= (n - 1) / B; ++i) {
            lazy[i] += lazy[i - 1];
        }

        ans = 0;
        vector<array<int, 2>> segments;
        if (l / B == r / B) {
            segments.push_back({l, r});
        } else {
            int a = l - l % B + B, b = r - r % B - 1;
            segments.push_back({l, a - 1});
            segments.push_back({b + 1, r});
            for (int i = a / B; i <= b / B; ++i) {
                ans = max(ans, lazy[i] + maxi[i]);
            }
        }

        for (auto [u, v] : segments) {
            fill(maxi, maxi + B, 0);
            for (auto [a, b, i] : updates[u / B]) {
                if (i < q) {
                    ++maxi[a];
                    if (b + 1 < B) {
                        --maxi[b + 1];
                    }
                }
            }

            for (int i = 0; i < B; ++i) {
                if (i > 0) {
                    maxi[i] += maxi[i - 1];
                }

                if (i >= u % B && i <= v % B) {
                    ans = max(ans, lazy[u / B] + maxi[i]);
                }
            }
        }

        ans = m - ans;

        cout << ans << "\n";
    }
}