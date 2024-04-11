#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N; cin >> N;
    int res[3];
    res[1] = res[2] = N / 3;
    res[N % 3]++;
    cout << res[1] << " " << res[2] << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt; cin >> tt;
    while (tt--)
        solve();
    return 0;
}