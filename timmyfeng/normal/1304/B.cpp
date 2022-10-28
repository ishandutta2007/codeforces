#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string mid = "";
    string start = "";
    string fin = "";
    set<string> seen;
    while (n--) {
        string s;
        cin >> s;
        string t = s;
        reverse(t.begin(), t.end());
        if (t == s) {
            mid = t;
        } else if (seen.count(t)) {
            start += s;
            fin = t + fin;
        } else {
            seen.insert(s);
        }
    }
    string sol = start + mid + fin;
    cout << sol.size() << '\n';
    if (!sol.empty()) {
        cout << sol << '\n';
    }
}