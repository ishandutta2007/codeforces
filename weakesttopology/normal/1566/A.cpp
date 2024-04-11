#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N, S;
        cin >> N >> S;
        int M = N - (N + 1) / 2 + 1;
        int ans = S / M;
        cout << ans << '\n';
    }
    exit(0);
}