#include <bits/stdc++.h>
using namespace std;

bool v[100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int now = 0;
        for (int j = 0; j < k; ++j) {
            int c; cin >> c;
            now = now * 2 + c;
        }
        v[now] = true;
    }
    for (int i = 0; i < 1 << k; ++i) {
        for (int j = 0; j < 1 << k; ++j) {
            if ((i & j) == 0) if (v[i] && v[j]) return cout << "YES" << endl, 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}