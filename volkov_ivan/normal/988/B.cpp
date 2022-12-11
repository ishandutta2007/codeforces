#include <iostream>
#include <algorithm>

using namespace std;

bool is_substr(string s, string t) {
    for (int i = 0; i < s.length(); i++) {
        if (i + t.length() > s.length()) break;
        string now = "";
        for (int j = 0; j < t.length(); j++) {
            now += s[i + j];
        }
        if (now == t) return 1;
    }
    return 0;
}

bool cmp(string a, string b) {
    return (a.length() < b.length());
}

int main() {
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    stable_sort(s, s + n, cmp);
    for (int i = 1; i < n; i++) {
        if (!is_substr(s[i], s[i - 1])) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) cout << s[i] << endl;
    return 0;
}