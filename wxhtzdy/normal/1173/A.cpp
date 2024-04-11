#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y, z;
    std::cin >> x >> y >> z;

    std::set<char> ans;
    for (int i = 0; i <= z; i++) {
        int nx = i + x, ny = z - i + y;
        if (nx < ny) ans.insert('-');
        if (nx == ny) ans.insert('0');
        if (nx > ny) ans.insert('+');
    }

    if (ans.size() == 1) std::cout << *ans.begin() << "\n";
    else std::cout << "?\n";

    return 0;
}