#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (auto &i : a) cin >> i;

        vector<int> a_sorted = a;
        ranges::sort(a_sorted);

        cout << (a == a_sorted ? "NO" : "YES") << "\n";
    }
}