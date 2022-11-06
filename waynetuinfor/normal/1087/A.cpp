#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    string ans = "";
    deque<char> dq(s.begin(), s.end());
    if (s.size() & 1) {
        while (dq.size()) {
            if (dq.size()) ans += dq[0], dq.pop_front();
            if (dq.size()) ans += dq.back(), dq.pop_back();
        }
    } else {
        while (dq.size()) {
            if (dq.size()) ans += dq.back(), dq.pop_back();
            if (dq.size()) ans += dq[0], dq.pop_front();
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}