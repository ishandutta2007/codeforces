#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        string s; cin >> s;

        int ones = ranges::count(s, '1');
        int zeroes = ranges::count(s, '0');

        cout << min(ones, zeroes) - (ones == zeroes) << "\n";
    }
}