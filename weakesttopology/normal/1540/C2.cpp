#include <bits/stdc++.h>
using namespace std;
template<long long P>
struct Z {
    long long x;
    Z() : x(0) {}
    Z(long long x_) {
        x = x_ % P;
        if (x < 0) x += P;
    }
    Z& operator+=(Z rhs) {
        x += rhs.x;
        if (x >= P) x -= P;
        return *this;
    }
    Z& operator-=(Z rhs) {
        x -= rhs.x;
        if (x < 0) x += P;
        return *this;
    }
    Z& operator*=(Z rhs) {
        x = x * rhs.x % P;
        return *this;
    }
    Z& operator/=(Z rhs) {
        return *this *= rhs.power(-1);
    }
    Z power(long long p) const {
        p %= P - 1;
        if (p < 0) p += P - 1;
        Z res = 1;
        for (Z y = *this; p; p >>= 1, y *= y) if (p & 1) res *= y;
        return res;
    }
    Z operator-() const {
        return Z() - *this;
    }
    bool operator==(Z rhs) const {
        return x == rhs.x;
    }
    bool operator!=(Z rhs) const {
        return x != rhs.x;
    }
    bool operator<(Z rhs) const {
        return x < rhs.x;
    }
    friend Z operator+(Z lhs, Z rhs) {
        return lhs += rhs;
    }
    friend Z operator-(Z lhs, Z rhs) {
        return lhs -= rhs;
    }
    friend Z operator*(Z lhs, Z rhs) {
        return lhs *= rhs;
    }
    friend Z operator/(Z lhs, Z rhs) {
        return lhs /= rhs;
    }
    friend ostream& operator<<(ostream& out, Z a) {
        return out << a.x;
    }
    friend istream& operator>>(istream& in, Z& a) {
        long long x;
        in >> x;
        a = Z(x);
        return in;
    }
    inline static const Z X = [](){
        uniform_int_distribution<long long> unif(1, P - 1);
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        return unif(rng);
    }(), Xinv = 1 / X;
};
using Zp = Z<(int)1e9 + 7>;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> c(N), b(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> b[i];
    }
    partial_sum(b.begin(), b.end(), b.begin());
    partial_sum(b.begin(), b.end(), b.begin());
    auto solve = [&](int x) {
        if (x > c[0]) return Zp();
        vector<Zp> dp(c[0] + 1);
        fill(dp.begin() + max(0, x), dp.end(), 1);
        for (int i = 0; i + 1 < N; ++i) {
            vector<Zp> nxt(dp.size() + c[i + 1]);
            for (int w = 0; w < (int)dp.size(); ++w) {
                nxt[w] += dp[w];
                if (w + 1 < (int)dp.size()) {
                    nxt[w + c[i + 1] + 1] -= dp[w];
                }
            }
            partial_sum(nxt.begin(), nxt.end(), nxt.begin());
            fill(nxt.begin(), nxt.begin() + clamp(b[i] + (i + 2) * x, 0, (int)nxt.size()), 0);
            swap(dp, nxt);
        }
        return accumulate(dp.begin(), dp.end(), Zp());
    };
    const int L = -b.back() / N, R = *max_element(c.begin(), c.end()) - b.back() / N;
    map<int, Zp> memo;
    for (int x = L; x <= R; ++x) {
        memo[x] = solve(x);
    }
    Zp tot = 1;
    for (int i = 0; i < N; ++i) {
        tot *= c[i] + 1;
    }
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int x;
        cin >> x;
        Zp ans = (x < L ? tot : x > R ? Zp() : memo[x]);
        cout << ans << '\n';
    } 
    exit(0);
}