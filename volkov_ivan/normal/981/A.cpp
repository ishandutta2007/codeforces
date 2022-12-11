#include <iostream>
#include <algorithm>

using namespace std;

bool check(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return (s == t);
}

int main() {
    string s;
    cin >> s;
    string t = "";
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        t = "";
        for (int j = i; j < s.length(); j++) {
            t += s[j];
            if (!check(t)) ans = max(ans, (int) t.length());
        }
    }
    cout << ans << endl;
    return 0;
}