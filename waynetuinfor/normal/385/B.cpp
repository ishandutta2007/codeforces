#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    if (s.length() < 4) return cout << "0" << endl, 0;
    long long ans = 0;
    int prv = -1;
    for (int i = 0; i < s.length() - 3; ++i) {
        if (s.substr(i, 4) == "bear") {
            ans += (i - prv) * (s.length() - i - 3);
            prv = i;
        }
    }
    cout << ans << endl;
}