#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

template <class T>
vector<T> Vec(size_t l, T v) { return vector<T>(l, v); }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}

template <typename T>
inline T sq(T a) { return a * a; }

template <typename T, typename U>
T mpow(T b, U n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * b % MOD;
        n >>= 1;
        b = b * b % MOD;
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    map<int, vector<pair<int, int>>> coo;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < M; ++y) {
            int a;
            cin >> a;
            coo[a].push_back(make_pair(x, y));
        }
    }

    auto score = Vec<ll>(N, M, 0LL);

    ll cnt = 0, scoresum = 0, xsum = 0, x2sum = 0, ysum = 0, y2sum = 0;
    for (const auto& q : coo) {
        ll inv = mpow(cnt, MOD - 2);

        if (cnt > 0) {
            for (const auto& p : q.second) {
                int x, y;
                tie(x, y) = p;
                score[x][y] = (scoresum + x2sum + y2sum + (MOD - 2 * x * xsum % MOD) + (MOD - 2 * y * ysum % MOD)) * inv % MOD;
                score[x][y] = (score[x][y] + sq(x) + sq(y)) % MOD;
            }
        }

        for (const auto& p : q.second) {
            ++cnt;
            int x, y;
            tie(x, y) = p;

            scoresum += score[x][y];
            x2sum += sq(x);
            y2sum += sq(y);
            xsum += x;
            ysum += y;

            if (scoresum >= MOD) scoresum -= MOD;
            if (x2sum >= MOD) x2sum -= MOD;
            if (y2sum >= MOD) y2sum -= MOD;
            if (xsum >= MOD) xsum -= MOD;
            if (ysum >= MOD) ysum -= MOD;
        }
    }

    int x, y;
    cin >> x >> y;
    cout << score[x - 1][y - 1] << endl;
    return 0;
}