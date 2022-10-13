#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        bool work = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1' and t[i] == '1') {
                work = true;
            }
        }
        if (work) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
}