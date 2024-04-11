#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int a[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> a[i][j];
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        bool col = false;
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == 1 || a[i][j] == 3) col = true;
        }
        if (!col) ans.push_back(i);
    }
    cout << ans.size() << endl;
    if (ans.size() == 0) return 0;
    for (int i : ans) cout << i << ' '; cout << endl;
    return 0;
}