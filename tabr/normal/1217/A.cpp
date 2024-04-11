#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int s, i, e;
        cin >> s >> i >> e;
        cout << max(0, min(e + 1, (s + e - i + 1) / 2)) << endl;
    }

    return 0;
}