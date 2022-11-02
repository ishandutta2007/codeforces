#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>

template <int K>
struct FastFourierTransform {
    using cplx = std::complex<double>;
    using cplxs = std::vector<cplx>;

    static constexpr double PI = 3.14159265358979;

    cplxs zetas;

    explicit FastFourierTransform() : zetas(K) {
        for (int i = 0; i < K; ++i) {
            zetas[i] = std::polar(1., PI * 2 / (1 << i));
        }
    }

    void bitrev(cplxs& f) const {
        int n = f.size();

        for (int i = 0; i < n; ++i) {
            int ti = i, ni = 0;
            for (int k = 0; (1 << k) < n; ++k) {
                int b = (ti & 1);
                ti >>= 1;
                ni <<= 1;
                ni += b;
            }

            if (i < ni) std::swap(f[i], f[ni]);
        }
    }

    void udft(cplxs& f, bool isinv) const {
        if (f.size() <= 1) return;

        int l = 1;
        int k = 1 << l;
        int n = f.size();

        while (k <= n) {
            auto zeta = zetas[l];
            if (isinv) zeta = std::conj(zeta);

            for (int r = 0; r < n / k; ++r) {
                cplx zetapow = 1;

                for (int j = 0; j < k / 2; ++j) {
                    int b = r * k + j;
                    auto t = zetapow * f[b + k / 2];

                    f[b + k / 2] = f[b] - t;
                    f[b] = f[b] + t;

                    zetapow *= zeta;
                }
            }

            ++l;
            k <<= 1;
        }
    }

    void dft(cplxs& f, bool isinv) const {
        bitrev(f);
        udft(f, isinv);
    }

    // main routine
    using lint = long long;
    using lints = std::vector<lint>;

    lints fft(const lints& ff, const lints& gf) const {
        auto f = li2cp(ff),
             g = li2cp(gf);

        int fdeg = f.size(),
            gdeg = g.size();

        int k = 0;
        while ((1 << k) < fdeg + gdeg) ++k;

        int n = (1 << k);
        f.resize(n, 0);
        g.resize(n, 0);

        dft(f, false);
        dft(g, false);

        cplxs h(n);
        for (int i = 0; i < n; ++i) h[i] = f[i] * g[i];

        dft(h, true);
        h.resize(fdeg + gdeg - 1);
        for (auto& x : h) x /= n;

        return cp2li(h);
    }

    // lint <-> complex
    cplxs li2cp(const lints& f) const {
        cplxs ret;
        std::transform(f.begin(), f.end(), std::back_inserter(ret),
                       [](auto x) { return cplx(x); });
        return ret;
    }

    lints cp2li(const cplxs& f) const {
        lints ret;
        std::transform(f.begin(), f.end(), std::back_inserter(ret),
                       [](auto x) { return std::llround(x.real()); });
        return ret;
    }
};

struct Prime {
    int max_n;
    std::vector<int> primes;
    std::vector<bool> isp;

    explicit Prime(int max_n)
        : max_n(max_n), isp(max_n + 1, true) {
        isp[0] = isp[1] = false;
        for (int i = 2; i * i <= max_n; ++i) {
            if (isp[i]) {
                for (int j = i; i * j <= max_n; ++j) {
                    isp[i * j] = false;
                }
            }
        }

        for (int p = 2; p <= max_n; ++p) {
            if (isp[p]) primes.push_back(p);
        }
    }

    template <class T>
    bool isprime(T n) const {
        if (n <= max_n) return isp[n];
        for (T p : primes) {
            if (p * p > n) break;
            if (n % p == 0) return false;
        }
        return true;
    }

    template <class T>
    std::vector<std::pair<T, int>> factorize(T n) const {
        std::vector<std::pair<T, int>> facts;
        for (T p : primes) {
            if (p * p > n) break;
            if (n % p != 0) continue;
            int exp = 0;
            while (n % p == 0) {
                n /= p;
                ++exp;
            }
            facts.emplace_back(p, exp);
        }
        if (n > 1) {
            facts.emplace_back(n, 1);
        }
        return facts;
    }

    template <class T>
    static std::vector<T> divisors(T n) {
        std::vector<T> ret;
        for (T p = 1; p * p <= n; ++p) {
            if (n % p != 0) continue;
            ret.push_back(p);
            if (n / p == p) continue;
            ret.push_back(n / p);
        }
        return ret;
    }
};

using lint = long long;
FastFourierTransform<20> FFT;

constexpr int W = 500000;

void solve() {
    std::vector<std::vector<int>> divs(W + 1);
    for (int p = 1; p <= W; ++p) {
        for (int q = p; q <= W; q += p) {
            divs[q].push_back(p);
        }
    }

    int n, h, w;
    std::cin >> n >> h >> w;

    std::vector<lint> pcnt(h + 1, 0), ncnt(h + 1, 0);
    ++n;
    while (n--) {
        int x;
        std::cin >> x;
        ++pcnt[x], ++ncnt[h - x];
    }
    auto conv = FFT.fft(pcnt, ncnt);

    std::vector<bool> ok(h + 1, false);
    for (int d = 1; d <= h; ++d) ok[d] = (conv[h - d] > 0);

    int q;
    std::cin >> q;
    std::vector<int> anss(W + 1, -2);

    while (q--) {
        int l;
        std::cin >> l;
        l /= 2;

        auto& ans = anss[l];
        if (ans != -2) {
            std::cout << ans << " ";
            continue;
        }
        ans = -1;

        const auto& ds = divs[l];
        for (auto d : ds) {
            int e = d - w;
            if (0 <= e && e <= h && ok[e]) {
                ans = std::max(ans, d * 2);
            }
        }

        std::cout << ans << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}