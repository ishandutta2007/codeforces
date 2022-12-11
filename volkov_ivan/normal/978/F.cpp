#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, v, u, cnt = 0;
    cin >> n >> m;
    vector <int> bad[n + 1];
    pair <int, int> r[n];
    int real_r[n];
    for (int i = 0; i < n; i++) {
        cin >> r[i].first;
        r[i].second = i;
        real_r[i] = r[i].first;
    }
    int ans[n];
    for (int i = 0; i < m; i++) {
        cin >> v >> u;
        bad[v].push_back(u);
    }
    sort(r, r + n);
    ans[r[0].second] = 0;
    for (int i = 1; i < n; i++) {
        if (r[i].first != r[i - 1].first) cnt = i;
        ans[r[i].second] = cnt;
    }
    for (int i = 1; i <= n; i++) {
        for (int elem : bad[i]) {
            if (real_r[i - 1] > real_r[elem - 1]) ans[i - 1]--;
            if (real_r[elem - 1] > real_r[i - 1]) ans[elem - 1]--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}