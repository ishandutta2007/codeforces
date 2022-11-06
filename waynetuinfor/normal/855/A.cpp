#include <bits/stdc++.h>
using namespace std;

set<string> s;

int main() {
    int n; cin >> n; while (n--) {
        string t; cin >> t;
        if (s.size() && s.count(t)) cout << "YES" << endl;
        else cout << "NO" << endl;
        s.insert(t);
    }
}