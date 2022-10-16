#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        const int s = *min_element(begin(a), end(a));
        const int t = *max_element(begin(a), end(a));
        cout << t - s << '\n';
    }
}