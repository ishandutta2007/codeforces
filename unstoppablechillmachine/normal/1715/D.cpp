#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 1e5 + 10;
bool is_zero[N][30];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int n, q;
    cin >> n >> q;
    vector<int> a(q), b(q), x(q);
    vector<vector<pair<int, int>>> que(n);
    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i] >> x[i];
        a[i]--;
        b[i]--;
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
        }
        que[a[i]].emplace_back(b[i], x[i]);
        for (int j = 0; j < 30; j++) {
            if (!((x[i] >> j) & 1)) {
                is_zero[a[i]][j] = is_zero[b[i]][j] = true;
            }
        }
    }
    vector<int> answer(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto it : que[i]) {
            for (int bit = 0; bit < 30; bit++) {
                if (((it.second >> bit) & 1) && (is_zero[it.first][bit] || it.first == i)) {
                    answer[i] |= 1 << bit;
                }
            }
        }

        for (auto it : que[i]) {
            for (int bit = 0; bit < 30; bit++) {
                if (((it.second >> bit) & 1) && (!((answer[i] >> bit) & 1))) {
                    answer[it.first] |= 1 << bit;
                }
            }
        }
    }
    for (int i = 0; i < q; i++) {
        assert((answer[a[i]] | answer[b[i]]) == x[i]);
    }
    for (auto i : answer) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}