/* ---------- STL Libraries ---------- */

// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

/* ---------- Namespace ---------- */

using namespace std;

/* ---------- Type Abbreviation ---------- */

using ll = long long;

template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

#define mp make_pair
#define mt make_tuple

/* ----------- debug ---------- */

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p);

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, set<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

/* ---------- Constants ---------- */

// const ll MOD = 1000000007;
// const ll MOD = 998244353;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// mt19937 mert(LL(time(0)));

/* ---------- Short Functions ---------- */

template <typename T>
inline T sq(T a) { return a * a; }

template <typename T>
T gcd(T a, T b) {
    if (a > b) return gcd(b, a);
    return a == 0 ? b : gcd(b % a, a);
}

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b /* % MOD */;
    if (n % 2 == 0) {
        return mypow(b * b /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

ll pcnt(ll b) {
    return __builtin_popcountll(b);
}

template <typename T>
T iceil(T n, T d) {
    return (n + d - 1) / d;
}

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

int N, M;
vector<vector<int>> s;
map<char, int> c2i = {{'A', 0}, {'G', 1}, {'C', 2}, {'T', 3}};
string i2c = "AGCT";

int col_cost(int n, int a, int b) {
    int cost = 0;
    for (int m = 0; m < M; ++m) {
        if (m % 2 == 0) {
            cost += (a != s[n][m]);
        } else {
            cost += (b != s[n][m]);
        }
    }
    return cost;
}

int row_cost(int m, int a, int b) {
    int cost = 0;
    for (int n = 0; n < N; ++n) {
        if (n % 2 == 0) {
            cost += (a != s[n][m]);
        } else {
            cost += (b != s[n][m]);
        }
    }
    return cost;
}

int main() {
    cin >> N >> M;

    string S[N];
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    s.resize(N);
    for (int i = 0; i < N; ++i) {
        s[i].resize(M);
        for (int j = 0; j < M; ++j) {
            s[i][j] = c2i[S[i][j]];
        }
    }

    int mincost = N * M;
    int best[2];

    int a[2];
    for (a[0] = 0; a[0] < 4; ++a[0]) {
        for (a[1] = a[0] + 1; a[1] < 4; ++a[1]) {
            int b[2], j = 0;
            for (int i = 0; i < 4; ++i) {
                if (i != a[0] && i != a[1]) {
                    b[j] = i;
                    ++j;
                }
            }

            int cost = 0;

            for (int n = 0; n < N; ++n) {
                if (n % 2 == 0) {
                    cost += min(col_cost(n, a[0], a[1]), col_cost(n, a[1], a[0]));
                } else {
                    cost += min(col_cost(n, b[0], b[1]), col_cost(n, b[1], b[0]));
                }
            }

            if (cost < mincost) {
                memcpy(&best, &a, sizeof(best));
                mincost = cost;
            }
        }
    }

    bool row = false;
    for (a[0] = 0; a[0] < 4; ++a[0]) {
        for (a[1] = a[0] + 1; a[1] < 4; ++a[1]) {
            int b[2], j = 0;
            for (int i = 0; i < 4; ++i) {
                if (i != a[0] && i != a[1]) {
                    b[j] = i;
                    ++j;
                }
            }

            int cost = 0;

            for (int m = 0; m < M; ++m) {
                if (m % 2 == 0) {
                    cost += min(row_cost(m, a[0], a[1]), row_cost(m, a[1], a[0]));
                } else {
                    cost += min(row_cost(m, b[0], b[1]), row_cost(m, b[1], b[0]));
                }
            }

            if (cost < mincost) {
                memcpy(&best, &a, sizeof(best));
                mincost = cost;
                row = true;
            }
        }
    }

    memcpy(&a, &best, sizeof(a));
    int b[2], j = 0;
    for (int i = 0; i < 4; ++i) {
        if (i != a[0] && i != a[1]) {
            b[j] = i;
            ++j;
        }
    }

    vector<string> ans(N, string(M, '$'));

    if (!row) {
        for (int n = 0; n < N; ++n) {
            if (n % 2 == 0) {
                if (col_cost(n, a[0], a[1]) > col_cost(n, a[1], a[0])) swap(a[0], a[1]);
                for (int m = 0; m < M; ++m) {
                    ans[n][m] = i2c[a[m % 2]];
                }
            } else {
                if (col_cost(n, b[0], b[1]) > col_cost(n, b[1], b[0])) swap(b[0], b[1]);
                for (int m = 0; m < M; ++m) {
                    ans[n][m] = i2c[b[m % 2]];
                }
            }
        }
    } else {
        for (int m = 0; m < M; ++m) {
            if (m % 2 == 0) {
                if (row_cost(m, a[0], a[1]) > row_cost(m, a[1], a[0])) swap(a[0], a[1]);
                for (int n = 0; n < N; ++n) {
                    ans[n][m] = i2c[a[n % 2]];
                }
            } else {
                if (row_cost(m, b[0], b[1]) > row_cost(m, b[1], b[0])) swap(b[0], b[1]);
                for (int n = 0; n < N; ++n) {
                    ans[n][m] = i2c[b[n % 2]];
                }
            }
        }
    }

    for (int n = 0; n < N; ++n) {
        cout << ans[n] << endl;
    }
    return 0;
}