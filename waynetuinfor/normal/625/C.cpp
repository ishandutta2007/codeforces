#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 5;
int a[maxn][maxn];

int main() {
    int n, k; cin >> n >> k;
    vector<int> v;
    int cur = n * n;
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= k - 1; --j) a[i][j] = cur--; 
    }
    for (int i = 0; i < n; ++i) {
        for (int j = k - 2; j >= 0; --j) a[i][j] = cur--;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += a[i][k - 1];
    cout << ans << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}