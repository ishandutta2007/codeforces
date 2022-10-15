#include <bits/stdc++.h>
using cpx = std::complex<int64_t>;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, b;
    std::cin >> a >> b;
    for (int x = 1; x <= a; ++x) {
        for (int y = 1; y <= a; ++y) {
            cpx p(x, y), q(-y, x);
            q *= b;
            if (norm(p) != a * a || q.real() % a || q.imag() % a) continue;
            q /= a;
            for (int t = 0; t < 2; ++t) {
                q *= -1;
                cpx r = p - q;
                if (r.real() && r.imag()) {
                    std::cout << "YES\n";
                    std::cout << "0 0\n" << p.real() << ' ' << p.imag() << '\n' << q.real() << ' ' << q.imag() << '\n';
                    exit(0);
                }
            }
        }
    }
    std::cout << "NO\n";
    exit(0);
}