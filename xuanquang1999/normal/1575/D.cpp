#include <bits/stdc++.h>

using namespace std;

int cnt(string s) {
    auto is_ok = [] (string &s) {
        int n = s.length();
        if (n == 1) return s[0] == '0';
        if (s[0] == '0') return false;
        return ((s[n-2]-'0')*10 + (s[n-1]-'0')) % 25 == 0;
    };

    int ans = 0;
    string cur;

    function<void(int)> backtrack;
    backtrack = [&] (int i) {
        if (i == s.length()) {
            if (is_ok(cur))
                ++ans;
            return;
        }

        char lo = (s[i] == '_') ? '0' : s[i];
        char hi = (s[i] == '_') ? '9' : s[i];
        for(char c = lo; c <= hi; ++c) {
            cur += c;
            backtrack(i+1);
            cur.pop_back();
        }
    };

    backtrack(0);
    return ans;
}

int main() {
    string s;
    cin >> s;

    int n = s.length();
    bool hasX = false;
    for(int i = 0; i < n; ++i)
        if (s[i] == 'X')
            hasX = true;

    int ans = 0;
    if (hasX) {
        for(char d = '0'; d <= '9'; ++d) {
            string t = s;
            for(int i = 0; i < n; ++i)
                if (t[i] == 'X') t[i] = d;
            ans += cnt(t);
        }
    } else
        ans += cnt(s);

    cout << ans;

    return 0;
}