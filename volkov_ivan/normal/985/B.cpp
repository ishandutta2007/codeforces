#include <iostream>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    int cnt[m];
    for (int i = 0; i < m; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') cnt[j]++;
        }
    }
    bool ok;
    for (int i = 0; i < n; i++) {
        ok = 1;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1' && cnt[j] < 2) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}