#include <iostream>

using namespace std;

bool check() {
    int res = 0;
    for (int i = 0; i < 100000000; i++) {
        res = (res * 3 + i) % 5;
    }
    if (res >= 0) return 1;
    return 0;
}

int main() {
    ios_base :: sync_with_stdio(0);
    check();
    int n, m;
    cin >> n >> m;
    bool ok[m + 1];
    for (int i = 1; i <= m; i++) ok[i] = 1;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        for (int j = l; j <= r; j++) ok[j] = 0;
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) if (ok[i]) cnt++;
    cout << cnt << endl;
    for (int i = 1; i <= m; i++) if (ok[i]) cout << i << ' ';
    cout << endl;
    return 0;
}