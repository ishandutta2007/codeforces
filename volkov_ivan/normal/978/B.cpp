#include <iostream>

using namespace std;

int main() {
    int n, cnt = 0, ans = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'x') cnt++;
        else cnt = 0;
        if (cnt >= 3) ans++;
    }
    cout << ans << endl;
    return 0;
}