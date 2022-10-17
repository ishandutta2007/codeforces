#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        int answer = x;
        for (int cur = 1; cur <= x; cur *= 10) {
            answer = x - cur;
        }
        cout << answer << '\n';
    }
    return 0;
}