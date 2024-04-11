#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template <class Container>
std::vector<int> zalgo(const Container& dat) {
    int n = dat.size();

    std::vector<int> ret(n);
    if (n == 0) return ret;

    ret[0] = n;

    int i = 1, len = 0;
    while (i < n) {
        while (i + len < n && dat[len] == dat[i + len]) {
            ++len;
        }
        ret[i] = len;

        if (len == 0) {
            ++i;
            continue;
        }

        int nlen = 1;
        while (i + nlen < n && nlen + ret[nlen] < len) {
            ret[i + nlen] = ret[nlen];
            ++nlen;
        }

        i += nlen;
        len -= nlen;
    }

    return ret;
}

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();

    int i;
    for (i = 0; i < n - i - 1 && s[i] == s[n - i - 1]; ++i) {}

    auto t = s.substr(i, n - i * 2);
    int m = t.length();

    std::string center;

    for (int q = 0; q < 2; ++q) {
        auto tt = t;
        std::reverse(tt.begin(), tt.end());
        auto u = t + "$" + tt;

        auto zs = zalgo(u);

        int len = 0;
        for (int l = 1; l <= m; ++l) {
            int j = m * 2 - l + 1;
            if (zs[j] >= l) len = l;
        }

        if ((int)center.length() < len) {
            center = t.substr(0, len);
        }

        std::reverse(t.begin(), t.end());
    }

    auto p = s.substr(0, i);
    auto pp = p;
    std::reverse(pp.begin(), pp.end());

    std::cout << p + center + pp << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}