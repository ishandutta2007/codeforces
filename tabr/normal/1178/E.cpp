#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    if (n % 2 == 1) {
        s.pop_back();
        n--;
    }
    if (n == 2) {
        cout << s[0] << '\n';
        return 0;
    }
    string t;
    for (int i = 0; i < n; i += 2) {
        if (i + 1 < n - 2 - i) {
            vector<int> a(3);
            a[s[i] - 'a']++;
            a[s[i + 1] - 'a']++;
            a[s[n - 1 - i] - 'a']++;
            a[s[n - 2 - i] - 'a']++;
            char c = (char)('a' + max_element(a.begin(), a.end()) - a.begin());
            t.push_back(c);
        } else {
            string u = t;
            reverse(u.begin(), u.end());
            if (i == n - 2 - i) {
                t += s[i];
            }
            t += u;
            break;
        }
    }
    cout << t << '\n';
    return 0;
}