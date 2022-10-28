#include <bits/stdc++.h>
using namespace std;

const int L = 30, M = 998244353;

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

struct trie {
    trie *child[2];
    int sub;
};

int n, k;

mint subsets(trie *t) {
    return t ? mint(2).pow(t->sub) : 1;
}

mint solve(trie *t, trie *s, int bit) {
    if (!t || !s || bit == 0) return subsets(s) * subsets(t);

    if ((k & bit) == 0) {
        return solve(t->child[0], s->child[0], bit / 2) + solve(t->child[1], s->child[1], bit / 2) - 1 +
            (subsets(s->child[0]) - 1) * (subsets(s->child[1]) - 1) +
            (subsets(t->child[0]) - 1) * (subsets(t->child[1]) - 1);
    } else {
        return solve(t->child[0], s->child[1], bit / 2) * solve(t->child[1], s->child[0], bit / 2);
    }
}

mint solve(trie *t, int bit) {
    if (!t || bit == 0) return subsets(t);

    if ((k & bit) == 0) {
        return solve(t->child[0], bit / 2) + solve(t->child[1], bit / 2) - 1;
    } else {
        return solve(t->child[0], t->child[1], bit / 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    trie *t = new trie();

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        trie *u = t;
        ++u->sub;

        for (int bit = 1 << (L - 1); bit > 0; bit /= 2) {
            int dir = (x & bit) != 0;
            if (!u->child[dir]) u->child[dir] = new trie();
            u = u->child[dir];
            ++u->sub;
        }
    }

    cout << solve(t, 1 << (L - 1)) - 1 << "\n";
}