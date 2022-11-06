#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
string s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string p; cin >> p;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            string t[2] = { s[i] + s[j], s[j] + s[i] };
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 3; ++l) {
                    if (t[k].substr(l, 2) == p) return cout << "YES" << endl, 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}