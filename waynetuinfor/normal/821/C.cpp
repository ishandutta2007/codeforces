#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
bool v[maxn], sor;

int main() {
    stack<int> s; int n; cin >> n;
    int ans = 0, cur = 1;
    for (int i = 0; i < 2 * n; ++i) {
        string cmd; cin >> cmd;
        if (cmd == "add") {
            int x; cin >> x;
            s.push(x);
        } else {
            if (s.size() && s.top() == cur) s.pop();
            else if (s.size()) {
                ++ans;
                while (s.size()) s.pop();
            }
            ++cur;
        }
    }
    cout << ans << endl;
    return 0;
}