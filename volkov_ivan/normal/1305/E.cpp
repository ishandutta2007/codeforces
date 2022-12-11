#include <iostream>
#include <vector>
#define int long long

using namespace std;

const int INF = 1e9, N = 10007;

signed main() {
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        if (m == 0) cout << "1" << endl;
        else cout << "-1" << endl;
        return 0;
    }
    if (n == 2) {
        if (m == 0) cout << "1 2" << endl;
        else cout << "-1" << endl;
        return 0;
    }
    int ans[n];
    ans[0] = 1;
    ans[1] = 2;
    int need = m;
    for (int i = 2; i < n; i++) {
        int cur = i / 2;
        if (need == 0) {
            ans[i] = INF - (n - i) * N;
            continue;
        }
        if (cur <= need) {
            ans[i] = i + 1;
            need -= cur;
            continue;
        }
        ans[i] = i + (i - 2 * need) + 1;
        need = 0;
    }
    if (need != 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}