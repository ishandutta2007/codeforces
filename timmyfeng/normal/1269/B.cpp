#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    for (auto& i : a) {
        cin >> i;
    }
    for (auto &i : b) {
        cin >> i;
    }
    sort(b.begin(), b.end());

    int sol = 1e9;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        int x = (b[i] - a[0] + m) % m;
        for (int j = 0; j < n; ++j) {
            c[j] = (a[j] + x) % m;
        }
        sort(c.begin(), c.end());
        if (c == b) {
            sol = min(sol, x);
        }
    }
    cout << sol << '\n';
}