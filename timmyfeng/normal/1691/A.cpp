#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        int odd = 0, even = 0;
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            (a % 2 ? odd : even)++;
        }

        cout << min(odd, even) << "\n";
    }
}