#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
const int inf = 1e9;
stack<int> lim;

int main() {
    int n; cin >> n;
    int sp = 0;
    int ans = 0, ov = 0;
    while (n--) {
        int t; cin >> t;
        if (t == 1) cin >> sp;
        if (t == 2) ans += ov, ov = 0;
        if (t == 3) {
            int s; cin >> s;
            lim.push(s);
        }
        if (t == 4) ov = 0;
        if (t == 5) while (lim.size()) lim.pop();
        if (t == 6) ++ov;
        while (lim.size() && lim.top() < sp) ++ans, lim.pop();
    }
    cout << ans << endl;
}