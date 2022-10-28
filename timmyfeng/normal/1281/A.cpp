#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s.substr(s.size() - 2) == "po") {
            cout << "FILIPINO\n";
        } else if (s.size() >= 5 && s.substr(s.size() - 5) == "mnida") {
            cout << "KOREAN\n";
        } else {
            cout << "JAPANESE\n";
        }
    }
}