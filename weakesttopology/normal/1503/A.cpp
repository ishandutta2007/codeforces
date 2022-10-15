#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (s[0] != '1' || s.back() != '1' || count(all(s), '0') % 2) {
        cout << "NO" << endl;
        return;
    }

    int ones = (int)count(all(s), '1');

    string a[2];
    for (int t = 0; t < 2; ++t) a[t].assign(n, '*');

    for (int i = 0, t = 0, cnt = 0; i < n; ++i) {
        if (s[i] == '1') {
            a[0][i] = a[1][i] = (cnt < ones / 2) ? '(' : ')';
            ++cnt;
        }
        else {
            a[0][i] = '(', a[1][i] = ')';
            if (t) swap(a[0][i], a[1][i]);
            t ^= 1;
        }
    }

    cout << "YES" << endl;
    for (int t = 0; t < 2; ++t) cout << a[t] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) solve();

    exit(0);
}