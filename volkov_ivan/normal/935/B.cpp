#include <iostream>
 
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0, now = -1, ans = 0;
    if (s[0] == 'U') {
        y++;
        now = 0;
    } else {
        x++;
        now = 1;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == 'U') y++;
        if (s[i] == 'R') x++;
        if (((x > y) && (now == 0)) || ((x < y) && (now == 1))) {
            ans++;
            now = 1 - now;
        }
    }
    cout << ans << endl;
    return 0;
}