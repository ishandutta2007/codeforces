#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        S.erase(unique(S.begin(), S.end()), S.end());
        int ans = min(2, (int)count(S.begin(), S.end(), '0'));
        cout << ans << '\n';
    }
    exit(0);
}