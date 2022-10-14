#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    if (N <= 3) {
        cout << "-1\n";
        return;
    }
    vector<int> x, y;
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0) x.push_back(i);
        else y.push_back(i);
    }
    swap(x[0], x[1]);
    reverse(y.begin(), y.end());
    for (int i : y) cout << i << " ";
    for (int i : x) cout << i << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt; cin >> tt;
    while (tt--) solve();
    return 0;
}