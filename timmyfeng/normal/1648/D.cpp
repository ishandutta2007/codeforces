#include <bits/stdc++.h>
using namespace std;

struct segtree {
    segtree *left, *right;
    long long max_offer, max_score, lazy_tag;

    segtree(int l, int r) {
        if (l + 1 < r) {
            int m = (l + r) / 2;
            left = new segtree(l, m);
            right = new segtree(m, r);
        }
        max_offer = max_score = lazy_tag = LLONG_MIN;
    }

    void apply(long long score) {
        if (max_offer > LLONG_MIN) {
            max_score = max(max_score, max_offer + score);
            lazy_tag = max(lazy_tag, score);
        }
    }

    void push() {
        if (lazy_tag > LLONG_MIN) {
            left->apply(lazy_tag);
            right->apply(lazy_tag);
            lazy_tag = LLONG_MIN;
        }
    }

    void pull() {
        max_offer = max(left->max_offer, right->max_offer);
        max_score = max(left->max_score, right->max_score);
    }

    void set_offer(int a, long long offer, long long score, int l, int r) {
        if (l + 1 == r) max_offer = offer, max_score = score;
        else {
            push();
            int m = (l + r) / 2;
            if (a < m) left->set_offer(a, offer, score, l, m);
            else right->set_offer(a, offer, score, m, r);
            pull();
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;

    vector a(3, vector<int>(n));
    for (auto &i : a) for (auto &j : i) cin >> j;

    vector psum(3, vector<long long>(n + 1));
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < n; ++j)
            psum[i][j + 1] = psum[i][j] + a[i][j];

    vector<array<int, 3>> offers;
    for (int i = 0; i < q; ++i) {
        int l, r, k; cin >> l >> r >> k;
        offers.push_back({l - 1, k, i});
        offers.push_back({r, 0, i});
    }
    sort(offers.begin(), offers.end());

    segtree *tree = new segtree(0, q);
    long long answer = LLONG_MIN;

    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        long long prefix_score = tree->max_score;
        while (ptr < 2 * q && offers[ptr][0] == i) {
            auto [_, k, offer_id] = offers[ptr++];
            if (k) tree->set_offer(offer_id, -k, prefix_score > LLONG_MIN ? prefix_score - k : LLONG_MIN, 0, q);
            else tree->set_offer(offer_id, LLONG_MIN, LLONG_MIN, 0, q);
        }

        tree->apply(psum[0][i + 1] - psum[1][i]);

        if (tree->max_score > LLONG_MIN) answer = max(answer, tree->max_score + psum[1][i + 1] + psum[2][n] - psum[2][i]);
    }

    cout << answer << "\n";
}