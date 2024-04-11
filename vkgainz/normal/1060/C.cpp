#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

long long dp[2001][2001];

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int x; cin >> x;
    vector<int> mna(n + 1, 1e9), mnb(m + 1, 1e9);
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = i; j < m; j++) {
            int len = j - i + 1;
            sum += b[j];
            mnb[len] = min(mnb[len], sum);
        }
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            int len = j - i + 1;
            sum += a[j];
            mna[len] = min(mna[len], sum);
        }
    }
    int ans = 0;
    for (int l1 = 1; l1 <= n; l1++) {
        for (int l2 = 1; l2 <= m; l2++) {
            if (mna[l1] * 1LL * mnb[l2] <= x) {
                ans = max(ans, l1 * l2);
            }
        }
    }
    cout << ans << "\n";
}