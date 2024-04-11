#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    string s;
    cin >> s;

    auto cell = [&](char c, char d) {
        return 'a' <= c && c <= 'h' && '1' <= d && d <= '8';
    };

    int ans = 0;
    for (int x : {-1, 0, 1}) {
        for (int y : {-1, 0, 1}) {
            if (x != 0 || y != 0) {
                ans += cell(s[0] + x, s[1] + y);
            }
        }
    }

    cout << ans << "\n";
}