#include <iostream>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
    }
    string res = "";
    for (int i = 0; i < m - 1; i++) res += "L";
    for (int i = 0; i < n - 1; i++) res += "U";
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m - 1; j++) {
                res += "R";
            }
        } else {
            for (int j = 0; j < m - 1; j++) {
                res += "L";
            }
        }
        if (i != n - 1) res += "D";
    }
    cout << res.size() << endl;
    cout << res << endl;
    return 0;
}