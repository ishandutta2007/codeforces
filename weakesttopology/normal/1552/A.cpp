#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        auto r = s;
        sort(begin(r), end(r));
        int k = 0;
        for (int i = 0; i < n; ++i) {
            k += s[i] != r[i];
        }
        cout << k << '\n';
    }
    exit(0);
}