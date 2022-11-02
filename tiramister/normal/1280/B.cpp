#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool allof(const std::vector<std::string>& ss, char c) {
    return std::all_of(ss.begin(), ss.end(),
                       [&](const auto& s) {
                           return std::all_of(s.begin(), s.end(),
                                              [&](char x) { return x == c; });
                       });
}

bool allrow(const std::vector<std::string>& ss, int i, char c) {
    for (int j = 0; j < (int)ss[i].size(); ++j) {
        if (ss[i][j] != c) return false;
    }
    return true;
}

bool allcol(const std::vector<std::string>& ss, int j, char c) {
    for (int i = 0; i < (int)ss.size(); ++i) {
        if (ss[i][j] != c) return false;
    }
    return true;
}

void solve() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> ss(h);
    for (auto& s : ss) std::cin >> s;

    if (allof(ss, 'P')) {
        std::cout << "MORTAL" << std::endl;
        return;
    }

    int ans = 4;

    if (!allrow(ss, 0, 'P') || !allrow(ss, h - 1, 'P') ||
        !allcol(ss, 0, 'P') || !allcol(ss, w - 1, 'P')) ans = 3;

    if (ss.front().front() == 'A' || ss.front().back() == 'A' ||
        ss.back().front() == 'A' || ss.back().back() == 'A') ans = 2;

    for (int i = 0; i < h; ++i) {
        if (allrow(ss, i, 'A')) ans = 2;
    }
    for (int j = 0; j < w; ++j) {
        if (allcol(ss, j, 'A')) ans = 2;
    }

    if (allrow(ss, 0, 'A') || allrow(ss, h - 1, 'A') ||
        allcol(ss, 0, 'A') || allcol(ss, w - 1, 'A')) ans = 1;

    if (allof(ss, 'A')) ans = 0;

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}