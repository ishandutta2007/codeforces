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
        string s;
        cin >> s;
        set<char> cur;
        int answer = 1;
        for (auto it : s) {
            if (cur.size() == 3 && !cur.count(it)) {
                answer++;
                cur = {it};
            } else {
                cur.insert(it);
            }
        }
        cout << answer << '\n';
    }
    return 0;
}