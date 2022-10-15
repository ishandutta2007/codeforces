#include <bits/stdc++.h>
template<typename T>
struct BIT {
    static int lsb(int b) { return b & -b; }
    int N, h;
    std::vector<T> ft;
    BIT(int N) : N(N), h(std::__lg(N)), ft(N + 1, T()) { }
    template<typename Iterator>
    BIT(Iterator first, Iterator last) : BIT(last - first) {
        for (int i = 1; i <= N; ++i) {
            ft[i] = first[i - 1] + ft[i - 1];
        }
        for (int i = N; i >= 1; --i) {
            ft[i] = ft[i] - ft[i - lsb(i)];
        }
    }
    T query(int p) const {
        T res = T();
        for (; p >= 1; p -= lsb(p)) {
            res = res + ft[p];
        }
        return res;
    }
    T query(int l, int r) const {
        return query(r) - query(l);
    }
    void update(int p, T value) {
        for (++p; p <= N; p += lsb(p)) {
            ft[p] = ft[p] + value;
        }
    }
    // returns first r such that pred(query(0, r + 1)) == false (N if no such r exists)
    template<typename Pred>
    int find_right(Pred&& pred) const {
        T prefix = T();
        int pos = 0;
        for (int x = h; x >= 0; --x) {
            int npos = pos + (1 << x);
            if (npos > N) continue;
            T nprefix = prefix + ft[npos];
            if (pred(nprefix)) {
                pos = npos;
                prefix = nprefix;
            }
        }
        return pos;
    }
    int lower_bound(T value) const {
        return find_right([value](T x) { return x < value; });
    }
};
template<int P>
struct Z {
    int x;
    Z() : x(0) {}
    Z(int64_t x_) {
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
        x = int64_t(x) * rhs.x % P;
        return *this;
    }
    Z& operator/=(Z rhs) {
        return *this *= rhs.power(-1);
    }
    Z power(int64_t p) const {
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
    friend std::ostream& operator<<(std::ostream& out, Z a) {
        return out << a.x;
    }
    friend std::istream& operator>>(std::istream& in, Z& a) {
        int64_t x;
        in >> x;
        a = Z(x);
        return in;
    }
    inline static const Z X = [](){
        std::uniform_int_distribution<int64_t> unif(1, P - 1);
        std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
        return unif(rng);
    }(), Xinv = 1 / X;
};
using Zp = Z<(int)1e9 + 7>;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    int max = *std::max_element(a.begin(), a.end());
    BIT<Zp> bit(max + 1);
    bit.update(0, 1);
    for (int i = 0; i < N; ++i) {
        int x = a[i];
        bit.update(a[i], bit.query(a[i] + 1) * x - bit.query(a[i], a[i] + 1));
    }
    std::cout << bit.query(max + 1) - 1 << '\n';
    exit(0);
}