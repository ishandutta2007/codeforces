#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<string, string> old;

    while (n--) {
        string s, t;
        cin >> s >> t;
        old[t] = old.count(s) > 0 ? old[s] : s;
        old.erase(s);
    }

    cout << old.size() << "\n";
    for (auto &[s, t] : old) {
        cout << t << " " << s << "\n";
    }
}