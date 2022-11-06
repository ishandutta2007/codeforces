#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    stack<int> s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        bool push = false;
        while (s.size()) {
            ans = max(ans, a ^ s.top());
            if (a < s.top()) {
                s.push(a);
                push = true;
                break;
            }
            s.pop();
        }
        if (!push) s.push(a);
    }
    cout << ans << endl;
    return 0;
}