#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        string t = s;
        int m = unique(t.begin(), t.end()) - t.begin();
        cout << (m == (int) set<char>(s.begin(), s.end()).size() ? "YES" : "NO") << "\n";
    }
}