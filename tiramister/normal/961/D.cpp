#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using lint = long long;

struct Line {
    lint a, b, c;

    Line(std::pair<lint, lint> p, std::pair<lint, lint> q) {
        a = q.second - p.second;
        b = p.first - q.first;
        c = q.first * p.second - p.first * q.second;
    }

    bool on(std::pair<lint, lint> p) {
        return a * p.first + b * p.second + c == 0;
    }
};

void exit(bool result) {
    std::cout << (result ? "YES" : "NO") << "\n";
    std::exit(0);
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<lint, lint>> ps(n);
    for (auto& p : ps) std::cin >> p.first >> p.second;

    if (n <= 2) exit(true);

    for (int i = 0; i < 3; ++i) {
        int j = (i + 1) % 3;
        Line l(ps[i], ps[j]);

        std::vector<std::pair<lint, lint>> qs;
        for (auto& p : ps) {
            if (!l.on(p)) qs.push_back(p);
        }

        if ((int)qs.size() <= 2) exit(true);

        Line m(qs[0], qs[1]);
        bool judge = true;
        for (auto& q : qs) {
            if (!m.on(q)) judge = false;
        }

        if (judge) exit(true);
    }

    exit(false);
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}