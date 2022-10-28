#include <bits/stdc++.h>
using namespace std;

const int N = 100001, BLOCK_SIZE = 64;

int prv[N], nxt[N], nxt_block[N];

int block[BLOCK_SIZE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> nxt[i];
        prv[nxt[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        int u = i;
        for (int j = 0; j < BLOCK_SIZE; ++j) u = nxt[u];
        nxt_block[i] = u;
    }

    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1) {
            swap(nxt[x], nxt[y]);
            swap(prv[nxt[x]], prv[nxt[y]]);

            for (int z : {x, y}) {
                for (int i = 0; i < BLOCK_SIZE; ++i) {
                    block[i] = nxt[i == 0 ? z : block[i - 1]];
                }

                for (int i = 0; i < BLOCK_SIZE; ++i) {
                    nxt_block[z] = block[BLOCK_SIZE - 1 - i];
                    z = prv[z];
                }
            }
        } else {
            while (BLOCK_SIZE <= y) {
                y -= BLOCK_SIZE;
                x = nxt_block[x];
            }

            while (y--) x = nxt[x];

            cout << x << "\n";
        }
    }
}