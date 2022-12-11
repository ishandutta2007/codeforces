#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b;
    bool ok[11];
    for (int i = 0; i < 11; i++) ok[i] = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> b;
        ok[b] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (ok[a[i]]) cout << a[i] << ' ';
    }
    return 0;
}