#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e6 + 10;
int a[maxn], b[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    int now = 0;
    vector<int> ans;
    for (int i = 1; i <= 2 * n * m; ++i) {
        now -= b[i];
        if (i > 1 && now == 0) {
            if (n > 1) ++now;
            ans.push_back(i - 1);
            ++b[i + n - 1];
        }
        now += a[i];
        a[i + m] += b[i];
        b[i + n] += a[i];
        while (now < k) {
            ++now;
            ++b[i + n]; 
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i << ' '; cout << endl;
    return 0;
}