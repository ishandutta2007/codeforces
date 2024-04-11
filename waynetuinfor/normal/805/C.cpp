#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> vec;
    int l = 1, r = n;
    while (true) {
        vec.push_back(l); vec.push_back(r);
        l++; r--;
        if (l >= r) break;
    }
    if (l == r) vec.push_back(l);
    int ans = 0;
    for (int i = 0; i < vec.size() - 1; ++i) ans += (vec[i] + vec[i + 1]) % (n + 1);
    cout << ans << '\n';
    return 0;
}