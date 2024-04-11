#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    deque<char> q;
    int cnt = 0;
    for (int i = 0; i < (int) s.length(); i++) {
        if ((int) q.size() > 0 && q.back() == s[i]) {
            cnt++;
            q.pop_back();
        } else {
            q.push_back(s[i]);
        }
    }
    if (cnt % 2 == 1) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n'; 
    }
    return 0;
}