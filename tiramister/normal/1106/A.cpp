#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; ++i) cin >> s[i];

    int ans = 0;
    for (int x = 1; x < n - 1; ++x) {
        for (int y = 1; y < n - 1; ++y) {
            if (s[x][y] != 'X') continue;

            bool judge = true;
            for (int dx = -1; dx <= 1; dx += 2) {
                for (int dy = -1; dy <= 1; dy += 2) {
                    if (s[x + dx][y + dy] != 'X') judge = false;
                }
            }

            if (judge) ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}