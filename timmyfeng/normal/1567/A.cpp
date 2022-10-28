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

        for (auto &i : s) {
            if (i == 'D') {
                i = 'U';
            } else if (i == 'U') {
                i = 'D';
            }
        }

        cout << s << "\n";
    }
}