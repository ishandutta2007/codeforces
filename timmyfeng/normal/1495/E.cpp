#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5000000, MOD = 1000000007;

struct mint {
    int x;

    mint() {}

    template <class T> mint(T value) : x(value % MOD) { if (x < 0) x += MOD; }

    mint & operator+=(const mint &oth) { x += oth.x; if (x >= MOD) x -= MOD; return *this; }

    mint & operator-=(const mint &oth) { x -= oth.x; if (x < 0) x += MOD; return *this; }

    mint & operator*=(const mint &oth) { x = (long long) x * oth.x % MOD; return *this; }

    friend mint operator+(mint l, const mint &r) { return l += r; }

    friend mint operator-(mint l, const mint &r) { return l -= r; }

    friend mint operator*(mint l, const mint &r) { return l *= r; }

    mint & operator--() { if (--x == -1) x = MOD - 1; return *this; }

    mint & operator++() { if (++x == MOD) x = 0; return *this; }

    mint operator--(int) { mint temp = *this; --*this; return temp; }

    mint operator++(int) { mint temp = *this; ++*this; return temp; }

    mint operator-() const { return 0 - *this; }

    mint operator+() const { return *this; }

    friend bool operator==(const mint &l, const mint &r) { return l.x == r.x; }

    friend bool operator!=(const mint &l, const mint &r) { return l.x != r.x; }

    friend ostream & operator<<(ostream &out, const mint &a) { return out << a.x; }

    mint pow(long long e = MOD - 2) const {
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

bool team[MAX_N];

int cards[MAX_N], ans[MAX_N];
long long total[2];

mint seed, base;

int rand_int() {
    int ans = seed.x;
    seed = seed * base + 233;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int prev = 0;
    while (m--) {
        int p, k, b, w;
        cin >> p >> k >> b >> w;
        seed = b, base = w;
        for (int i = prev; i < p; ++i) {
            team[i] = rand_int() % 2;
            cards[i] = rand_int() % k + 1;
        }
        prev = p;
    }

    for (int i = 0; i < n; ++i) {
        total[team[i]] += cards[i];
    }

    int player = 0;
    if (total[team[player]] > total[1 - team[player]]) {
        --cards[player], ++ans[player];
        player = find(team, team + n, 1 - team[player]) - team;
    }

    if (player < n) {
        long long balance = 0;
        int loser = team[player];
        for (int i = 0; i < 2 * n; ++i) {
            if (team[player] == loser) {
                balance += cards[player];
                ans[player] += cards[player];
                cards[player] = 0;
            } else {
                int delta = min(balance, (long long) cards[player]);
                balance -= delta;
                ans[player] += delta;
                cards[player] -= delta;
            }
            player = (player + 1) % n;
        }
    }

    mint product = 1;
    for (long long i = 1; i <= n; ++i) {
        product *= (ans[i - 1] ^ (i * i)) + 1;
    }

    cout << product << "\n";
}