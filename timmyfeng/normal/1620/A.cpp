#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        cout << (ranges::count(s, 'N') == 1 ? "NO" : "YES") << "\n"; 
    }
}