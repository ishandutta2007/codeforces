#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;
struct mint {

    int value;

    mint() : value(0) {}

    template <class T>
    mint(T x) {
        value = x % M;
        if (value < 0) {
            value += M;
        }
    }

    mint & operator++() {
        if (++value == M) {
            value = 0;
        }
        return *this;
    }

    mint & operator--() {
        if (--value == -1) {
            value = M - 1;
        }
        return *this;
    }

    mint operator++(int) {
        mint res = *this;
        ++*this;
        return res;
    }

    mint operator--(int) {
        mint res = *this;
        --*this;
        return res;
    }

    mint & operator+=(mint oth) {
        value += oth.value;
        if (value >= M) {
            value -= M;
        }
        return *this;
    }

    mint & operator-=(mint oth) {
        value -= oth.value;
        if (value < 0) {
            value += M;
        }
        return *this;
    }

    mint & operator*=(mint oth) {
        value = (long long) value * oth.value % M;
        return *this;
    }

    mint operator+() const {
        return *this;
    }

    mint operator-() const {
        return mint() - *this;
    }

    mint pow(long long e = M - 2) const {
        mint res = 1, b = *this;
        while (e > 0) {
            if (e % 2 == 1) {
                res *= b;
            }
            b *= b;
            e /= 2;
        }
        return res;
    }

    friend mint operator+(mint a, mint b) {
        return a += b;
    }

    friend mint operator-(mint a, mint b) {
        return a -= b;
    }

    friend mint operator*(mint a, mint b) {
        return mint(a) *= b;
    }

    friend bool operator==(mint a, mint b) {
        return a.value == b.value;
    }

    friend bool operator!=(mint a, mint b) {
        return a.value != b.value;
    }

    friend ostream & operator<<(ostream &out, mint a) {
        out << a.value;
        return out;
    }

};

const int N = 100000 + 1;
const int B = 512;

mint inv[2 * N], perm[N], ans[N], product;
int film[N], total[N], segment[N];
vector<array<int, 3>> queries[N];

void insert(int a) {
    a = film[a];
    product *= total[a] - segment[a];
    ++segment[a];
}

void erase(int a) {
    a = film[a];
    --segment[a];
    product *= inv[total[a] - segment[a]];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    inv[1] = 1;
    for (int i = 2; i < 2 * N; ++i) {
        inv[i] = -inv[M % i] * (M / i);
    }

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> film[i];
        ++total[film[i]];
    }

    for (int i = 1; i <= q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        queries[k].push_back({l, r, i});
    }

    for (int i = 0; i < N; ++i) {
        if (queries[i].empty()) {
            continue;
        }

        sort(queries[i].begin(), queries[i].end(),
            [&](array<int, 3> a, array<int, 3> b) {
                if (a[0] / B == b[0] / B) {
                    return a[1] < b[1];
                } else {
                    return a[0] < b[0];
                }
            }
        );

        for (int j = 1; j <= m; ++j) {
            total[j] += i;
            segment[j] = 0;
        }

        perm[0] = 1;
        for (int j = 1; j <= n; ++j) {
            perm[j] = perm[j - 1] * (mint(m) * i + j);
        }

        int l = 1, r = 0;
        product = 1;

        for (auto [a, b, id] : queries[i]) {
            while (l > a) {
                insert(--l);
            }
            while (r < b) {
                insert(++r);
            }
            while (l < a) {
                erase(l++);
            }
            while (r > b) {
                erase(r--);
            }
            ans[id] = product * perm[n - b + a - 1];
        }

        for (int j = 1; j <= m; ++j) {
            total[j] -= i;
        }
    }

    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << "\n";
    }
}