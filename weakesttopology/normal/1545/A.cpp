#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, array<int, 2>> f;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ++f[a][i % 2];
        }
        int o = 0;
        bool good = true;
        for (auto [x, v] : f) {
            int num = v[0] + v[1];
            if (v[o] != (num + 1) / 2 || v[o ^ 1] != num / 2) {
                good = false;
                break;
            }
            o ^= num % 2;
        }
        cout << (good ? "YES" : "NO") << '\n';
    }
    exit(0);
}