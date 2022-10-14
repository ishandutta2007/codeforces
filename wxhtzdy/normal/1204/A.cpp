#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int ans = ((int) s.size() + 1) / 2;
    int cnt = 0;
    for (char c : s) {
        cnt += c == '1';
    }
    if (cnt <= 1 && (int) (s.size() + 1) % 2 == 0) ans--;
    cout << ans << '\n';
    return 0;
}