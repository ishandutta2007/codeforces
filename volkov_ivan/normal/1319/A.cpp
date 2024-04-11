#include <iostream>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int a[n], b[n];
    int fi = 0, se = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && b[i] == 0) fi++;
        if (a[i] == 0 && b[i] == 1) se++;
    }
    if (fi == 0) {
        cout << -1 << endl;
        return 0;
    }
    se++;
    int res = (se + fi - 1) / fi;
    if (res == 0) res = 1;
    cout << res << endl;
    return 0;
}