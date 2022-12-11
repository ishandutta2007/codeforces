#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long

using namespace std;

const int N = 2e5 + 7, M = 1007;
int a[N], cnt[M];

signed main() {
    memset(cnt, 0, sizeof(cnt));
    ios_base :: sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    if (n > 1007) {
        cout << 0 << endl;
        return 0;
    }
    int res = 1;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            res = (res * abs(a[i] - a[j])) % m;
        }
    }
    cout << res << endl;
    return 0;
}