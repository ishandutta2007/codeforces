#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, bit = 30;
int b[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> b[i][j];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (i != j) {
            for (int k = 0; k < bit; ++k) {
                if (b[i][j] & (1 << k)) a[i] |= (1 << k), a[j] |= (1 << k);
            }
        }
    }
    for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl;
    return 0;
}