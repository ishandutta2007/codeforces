#include <bits/stdc++.h>
using namespace std;

const int N = 200001, M = 998244353;

struct mint {
    int x;

    mint() : x(0) {}

    template <class T> mint(T value) : x(value % M) { if (x < 0) x += M; }

    mint & operator+=(const mint &oth) { x += oth.x; if (x >= M) x -= M; return *this; }

    mint & operator-=(const mint &oth) { x -= oth.x; if (x < 0) x += M; return *this; }

    mint & operator*=(const mint &oth) { x = (long long) x * oth.x % M; return *this; }

    friend mint operator+(mint l, const mint &r) { return l += r; }

    friend mint operator-(mint l, const mint &r) { return l -= r; }

    friend mint operator*(mint l, const mint &r) { return l *= r; }

    mint & operator--() { if (--x == -1) x = M - 1; return *this; }

    mint & operator++() { if (++x == M) x = 0; return *this; }

    mint operator--(int) { mint temp = *this; --*this; return temp; }

    mint operator++(int) { mint temp = *this; ++*this; return temp; }

    mint operator-() const { return 0 - *this; }

    mint operator+() const { return *this; }

    friend bool operator==(const mint &l, const mint &r) { return l.x == r.x; }

    friend bool operator!=(const mint &l, const mint &r) { return l.x != r.x; }

    friend ostream & operator<<(ostream &out, const mint &a) { return out << a.x; }

    mint pow(long long e = M - 2) const {
        mint ans = 1, b = *this;
        while (e > 0) {
            if (e % 2 == 1) {
                ans *= b;
            }
            b *= b;
            e /= 2;
        }
        return ans;
    }
};

struct segtree {
    segtree *left = nullptr, *right = nullptr;
    mint sum = 0, lazy_m = 1, lazy_b = 0;

    void apply(int l, int r, mint m, mint b) {
        lazy_m *= m;
        lazy_b = m * lazy_b + b;
        sum = m * sum + b * (r - l + 1);
    }

    void pull() {
        sum = left->sum + right->sum;
    }

    void push(int l, int r) {
        if (!left) {
            left = new segtree();
            right = new segtree();
        }

        int m = (l + r) / 2;
        if (lazy_m != 1 || lazy_b != 0) {
            left->apply(l, m, lazy_m, lazy_b);
            right->apply(m + 1, r, lazy_m, lazy_b);
            lazy_m = 1, lazy_b = 0;
        }
    }

    void update(int a, int b, mint xm, mint xb, int l, int r) {
        if (b < l || r < a) {
            return;
        } else if (a <= l && r <= b) {
            apply(l, r, xm, xb);
        } else {
            push(l, r);
            int m = (l + r) / 2;
            left->update(a, b, xm, xb, l, m);
            right->update(a, b, xm, xb, m + 1, r);
            pull();
        }
    }

    mint query(int a, int b, int l, int r) {
        if (b < l || r < a) {
            return 0;
        } else if (a <= l && r <= b) {
            return sum;
        } else {
            push(l, r);
            int m = (l + r) / 2;
            return left->query(a, b, l, m) + right->query(a, b, m + 1, r);
        }
    }
};

map<int, int> ranges[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    segtree *sum = new segtree();

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1) {
            int x;
            cin >> x;

            sum->update(l, r, 1, 1, 1, n);

            auto it_l = ranges[x].lower_bound(l);
            auto it_r = it_l;

            while (it_r != ranges[x].end() && it_r->second <= r) {
                auto [b, a] = *it_r;
                sum->update(max(l, a), min(r, b), 2, -2, 1, n);
                ++it_r;
            }

            if (it_l != it_r) {
                auto it_m = it_r;
                --it_m;
                l = min(l, it_l->second);
                r = max(r, it_m->first);
                ranges[x].erase(it_l, it_r);
            }

            ranges[x].insert({r, l});
        } else {
            cout << sum->query(l, r, 1, n) << "\n";
        }
    }
}