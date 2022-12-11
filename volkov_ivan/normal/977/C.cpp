#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    if (k == 0) {
        if (a[0] == 1) cout << -1 << endl;
        else cout << 1 << endl;
        return 0;
    }
    if (k != n && a[k] == a[k - 1]) {
        cout << -1 << endl;
        return 0;
    }
    cout << a[k - 1] << endl;
    return 0;
}