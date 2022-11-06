#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main() {
    int n, x; cin >> n;
    while (n--) cin >> x, s.insert(x);
    if (s.size() < 2) return cout << "NO\n", 0;
    auto it = s.begin(); ++it; cout << *it << '\n';
    return 0;
}