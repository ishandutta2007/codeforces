#include <iostream>
#include <string>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int front = 0;
    while (front < (int)s.length() && s[front] != '>') ++front;

    int back = 0;
    while (back < (int)s.length() && s[n - back - 1] != '<') ++back;

    std::cout << std::min(front, back) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}