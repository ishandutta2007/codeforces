#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 400000;

struct segtree {
    struct segment {
        long long sum = 0, prefix = 0, suffix = 0, count = 0;

        segment combine(const segment &oth) {
            return {
                sum + oth.sum,
                prefix + oth.count * sum + oth.prefix,
                suffix + count * oth.sum + oth.suffix,
                count + oth.count
            };
        }
    };

    segtree *left = nullptr, *right = nullptr;
    segment value;

    void push() {
        if (!left) {
            left = new segtree();
            right = new segtree();
        }
    }

    void update(int a, long long x, int l, int r) {
        if (l == r) {
            value = x > 0 ? segment{x, x, x, 1} : segment();
        } else {
            push();
            int m = (l + r) / 2;
            if (a <= m) {
                left->update(a, x, l, m);
            } else {
                right->update(a, x, m + 1, r);
            }
            value = left->value.combine(right->value);
        }
    }

    segment query_prefix(int x, int l, int r) {
        if (x == 0) {
            return segment();
        } else if (value.count <= x) {
            return value;
        } else {
            push();
            int m = (l + r) / 2;
            segment temp = left->query_prefix(x, l, m);
            return temp.combine(right->query_prefix(x - temp.count, m + 1, r));
        }
    }

    segment query_suffix(int x, int l, int r) {
        if (x == 0) {
            return segment();
        } else if (value.count <= x) {
            return value;
        } else {
            push();
            int m = (l + r) / 2;
            segment temp = right->query_suffix(x, m + 1, r);
            return left->query_suffix(x - temp.count, l, m).combine(temp);
        }
    }
};

long long initial[MAX_N], values[MAX_N], update[MAX_N];
int type[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> initial[i];
        values[i] = initial[i];
    }

    for (int i = 0; i < q; ++i) {
        cin >> type[i] >> update[i];
        values[n + i] = update[i];
    }

    sort(values, values + n + q);
    int m = unique(values, values + n + q) - values;

    segtree *sum = new segtree();

    for (int i = 0; i < n; ++i) {
        int j = lower_bound(values, values + m, initial[i]) - values;
        sum->update(j, initial[i], 0, m - 1);
    }

    for (int i = 0; i <= q; ++i) {
        if (n == 0) {
            cout << 0 << "\n";
        } else {
            int low = 1, high = (n + 1) / 2;
            while (low < high) {
                int mid = (low + high + 1) / 2;
                if (sum->query_prefix(mid, 0, m - 1).sum - sum->query_suffix(mid - 1, 0, m - 1).sum > 0) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }

            if (low == (n + 1) / 2) {
                cout << sum->value.sum -
                    sum->query_prefix(n, 0, m - 1).prefix +
                    sum->query_suffix(n - 1, 0, m - 1).suffix << "\n";
            } else {
                cout << sum->value.sum -
                    2 * sum->query_prefix(low, 0, m - 1).prefix +
                    2 * sum->query_suffix(low - 1, 0, m - 1).suffix << "\n";
            }
        }

        if (i < q) {
            int j = lower_bound(values, values + m, update[i]) - values;
            if (type[i] == 1) {
                sum->update(j, update[i], 0, m - 1);
                ++n;
            } else {
                sum->update(j, 0, 0, m - 1);
                --n;
            }
        }
    }
}