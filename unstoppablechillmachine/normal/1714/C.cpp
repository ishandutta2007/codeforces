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
    vector<int> answer(46, 2e9);
    for (int i = 1; i < (1 << 9); i++) {
        int number = 0, sum = 0;
        for (int j = 0; j < 9; j++) {
            if ((i >> j) & 1) {
                number = number * 10 + j + 1;
                sum += j + 1;
            }
        }
        answer[sum] = min(answer[sum], number);
    }

    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        cout << answer[x] << '\n';
    }
    return 0;
}