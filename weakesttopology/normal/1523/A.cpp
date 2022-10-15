#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> left(n), right(n);
    for (int i = 0, last = -INF; i < n; ++i) {
        if (s[i] == '1') last = i;
        left[i] = i - last;
    }
    for (int i = n - 1, last = INF; i >= 0; --i) {
        if (s[i] == '1') last = i;
        right[i] = last - i;
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0' && left[i] != right[i] && min(left[i], right[i]) <= m) s[i] = '1';
    }

    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    exit(0);
}