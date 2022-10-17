#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

struct block_info {
    int pref, suf, sum, max_sum;
    block_info() : pref(0), suf(0), sum(0), max_sum(0) {}
    explicit block_info(int x) : sum(x), pref(max(0ll, x)), suf(max(0ll, x)), max_sum(max(0ll, x)) {}
};

block_info merge(const block_info &lhs, const block_info &rhs) {
    block_info res;
    res.sum = lhs.sum + rhs.sum;
    res.pref = max(lhs.pref, lhs.sum + rhs.pref);
    res.suf = max(rhs.suf, rhs.sum + lhs.suf);
    res.max_sum = max({lhs.max_sum, rhs.max_sum, lhs.suf + rhs.pref});
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<int> a(1 << n);
    for (auto &x : a) {
        cin >> x;
    }
    int block_size = 1 << (n / 2), cnt_blocks = (1 << n) / block_size;
    vector<vector<int>> order_inside_block(block_size, vector<int>(block_size)), order_of_blocks(cnt_blocks, vector<int>(cnt_blocks));

    iota(order_inside_block[0].begin(), order_inside_block[0].end(), 0);
    for (int mask = 1; mask < block_size; mask++) {
        int bit = 0;
        while (!((mask >> bit) & 1)) {
            bit++;
        }
        order_inside_block[mask] = order_inside_block[mask ^ (1 << bit)];
        for (int i = 0; i < block_size; i += 1 << (bit + 1)) {
            for (int j = i; j < i + (1 << bit); j++) {
                swap(order_inside_block[mask][j], order_inside_block[mask][j + (1 << bit)]);
            }
        }
    }

    iota(order_of_blocks[0].begin(), order_of_blocks[0].end(), 0);
    for (int mask = 1; mask < cnt_blocks; mask++) {
        int bit = 0;
        while (!((mask >> bit) & 1)) {
            bit++;
        }
        order_of_blocks[mask] = order_of_blocks[mask ^ (1 << bit)];
        for (int i = 0; i < cnt_blocks; i += 1 << (bit + 1)) {
            for (int j = i; j < i + (1 << bit); j++) {
                swap(order_of_blocks[mask][j], order_of_blocks[mask][j + (1 << bit)]);
            }
        }
    }

    vector<vector<block_info>> info(cnt_blocks, vector<block_info>(block_size));

    for (int block_id = 0; block_id < cnt_blocks; block_id++) {
        for (int mask = 0; mask < block_size; mask++) {
            info[block_id][mask].pref = info[block_id][mask].suf = info[block_id][mask].sum = info[block_id][mask].max_sum = 0;
            for (auto id : order_inside_block[mask]) {
                info[block_id][mask] = merge(info[block_id][mask], block_info(a[block_size * block_id + id]));
            }
        }
    }

    int q;
    cin >> q;
    int cur_mask = 0;
    for (int i = 0; i < q; i++) {
        int bit;
        cin >> bit;
        cur_mask ^= 1 << bit;
        block_info res;
        for (auto block_id : order_of_blocks[cur_mask / block_size]) {
            res = merge(res, info[block_id][cur_mask % block_size]);
        }
        cout << res.max_sum << '\n';
    }
    return 0;
}