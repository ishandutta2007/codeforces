#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
const int B = 512;

int par[N], root[N], maxi[B], n;
long long offset[B];

void update(int b) {
    if (maxi[b] == 0 || maxi[b] < B * b) {
        return;
    }

    maxi[b] = 0;
    for (int i = B * b; i < B * (b + 1) && i < n; ++i) {
        par[i] = max(0LL, par[i] - offset[b]);
        if (i == 0 || par[i] < B * b) {
            root[i] = i;
        } else {
            root[i] = root[par[i]];
        }
        maxi[b] = max(maxi[b], par[i]);
    }
    offset[b] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> q;

    for (int i = 1; i < n; ++i) {
        cin >> par[i];
        --par[i];
    }

    for (int i = 0; i <= (n - 1) / B; ++i) {
        maxi[i] = n;
        update(i);
    }

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;

            int bl = l / B, br = r / B;

            while (l <= r && l / B == bl) {
                par[l] = max(0, par[l] - x);
                ++l;
            }

            while (r >= l && r / B == br) {
                par[r] = max(0, par[r] - x);
                --r;
            }

            update(bl), update(br);

            for (int i = bl + 1; i < br; ++i) {
                offset[i] += x;
                update(i);
            }
        } else {
            int u, v;
            cin >> u >> v;
            --u, --v;

            while (root[u] != root[v]) {
                if (u < v) {
                    swap(u, v);
                }
                u = max(0LL, par[root[u]] - offset[u / B]);
            }

            while (u != v) {
                if (u < v) {
                    swap(u, v);
                }
                u = max(0LL, par[u] - offset[u / B]);
            }

            cout << u + 1 << "\n";
        }
    }
}