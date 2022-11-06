#include <bits/stdc++.h>
using namespace std;

int cnt[200];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int r; cin >> r;
        while (r--) {
            int x; cin >> x;
            ++cnt[x];
        }
    }
    for (int i = 1; i <= 100; ++i) if (cnt[i] == n) cout << i << ' ';
    cout << endl;
}