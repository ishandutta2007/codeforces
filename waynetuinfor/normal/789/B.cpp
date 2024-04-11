#include <bits/stdc++.h>
using namespace std;

set<long long> s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long b, q, l, m; cin >> b >> q >> l >> m;
    for (int i = 0; i < m; ++i) {
        long long a; cin >> a;
        s.insert(a);
    }
    if (abs(b) > l) return cout << "0\n", 0;
    if (b == 0 && s.find(0) == s.end()) return cout << "inf\n", 0;
    if (b == 0) return cout << "0\n", 0;
    if (q == 0 && s.find(0) == s.end()) {
        return cout << "inf\n", 0;
    }
    if (q == 0) {
        if (s.find(b) == s.end()) return cout << "1\n", 0;
        return cout << "0\n", 0;
    }
    if (q == 1 && s.find(b) == s.end()) {
        return cout << "inf\n", 0;
    }
    if (q == 1 && s.find(b) != s.end()) return cout << "0\n", 0;
    if (q == -1 && (s.find(b) == s.end() || s.find(-b) == s.end())) return cout << "inf\n", 0;
    if (q == -1) {
        return cout << "0\n", 0;
    }
    long long ans = 0;
    while (true) {
        if (abs(b) <= l && s.find(b) == s.end()) ++ans; 
        else if (abs(b) > l) break;
        b *= q;
    }
    cout << ans << '\n';
    return 0;
}