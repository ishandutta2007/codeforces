#include <bits/stdc++.h>
using namespace std;

const int M = 1000000009;
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

const int N = 100000;

set<int> below[N], above[N];
int locks[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<array<int, 2>, int> cubes;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        cubes[{x, y}] = i;
    }

    for (auto [p, i] : cubes) {
        if (p[1] > 0) {
            for (auto q : {p[0] - 1, p[0], p[0] + 1}) {
                if (cubes.count({q, p[1] - 1}) > 0) {
                    int j = cubes[{q, p[1] - 1}];
                    below[i].insert(j);
                    above[j].insert(i);
                }
            }
        }
    }

    set<int> stable;
    for (int i = 0; i < n; ++i) {
        for (auto j : above[i]) {
            locks[i] += below[j].size() == 1;
        }

        if (locks[i] == 0) {
            stable.insert(i);
        }
    }

    mint ans = 0;
    for (int i = 0; i < n; ++i) {
        int j;
        if (i % 2 == 0) {
            j = *--stable.end();
            stable.erase(--stable.end());
        } else {
            j = *stable.begin();
            stable.erase(stable.begin());
        }

        ans = n * ans + j;

        for (auto k : below[j]) {
            if (below[j].size() == 1) {
                if (--locks[k] == 0) {
                    stable.insert(k);
                }
            }
            above[k].erase(j);
        }

        for (auto k : above[j]) {
            below[k].erase(j);
            if (below[k].size() == 1) {
                int l = *below[k].begin();
                if (locks[l]++ == 0) {
                    stable.erase(l);
                }
            }
        }

        above[j].clear(), below[j].clear();
    }

    cout << ans << "\n";
}