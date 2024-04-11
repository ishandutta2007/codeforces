#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++ i)

#define all(c) std::begin(c), std::end(c)

#ifdef LOCAL
#define debug(...) debug_impl(#__VA_ARGS__, __VA_ARGS__)

template<class T, class ...Args> void debug_impl(string s, T&& first, Args &&...args) {
    cerr << "(" << s << ") : (" << forward<T>(first);
    ((cerr << ", " << forward<Args>(args)), ..., (cerr << ") " << "\n"));
}

#else
#define debug(...) void(0)
#endif

template<class T> bool chmax(T& a, const T& b) {
    return b > a ? (a = b, true) : false;
}

template<class T> bool chmin(T& a, const T& b) {
    return b < a ? (a = b, true) : false;
}

template<class ...Args> void read(Args &...args) {
    (cin >> ... >> args);
}

template<class T> ostream& operator<<(ostream& out, const vector<T>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        out << v[i];
        if (i + 1 != n) out << ' ';
    }
    return out;
}

template<class Head, class ...Tails> void print(Head&& h, Tails && ...tail) {
    cout << h, ((cout << ' ' << forward<Tails>(tail)), ..., (cout << '\n'));
}

constexpr long long inf = numeric_limits<long long>::max() / 2;

int main() {
    int n, k;
    read(n, k);
    vector<tuple<long long, long long, long long>> ps(n);
    rep(i, n) {
        long long x, w, c;
        read(x, w, c);
        w *= 200;
        c *= 2;
        ps[i] = { x, w, c };
    }
    sort(all(ps));

    vector<int> x(n);
    vector<long long> w(n), c(n);

    rep(i, n) {
        tie(x[i], w[i], c[i]) = ps[i];
    }

    vector<long long> dp(n, -inf);

    rep(i, n) {
        chmax(dp[i], -w[i]);
        rep(j, i) {
            chmax(dp[i], dp[j] + k * (c[i] + c[j]) / 2 * (x[i] - x[j]) - w[i]);
        }
    }

    debug(dp);

    long long ans = max(0LL, *max_element(all(dp)));

    cout << fixed << setprecision(4) << ans / 200. << endl;
}