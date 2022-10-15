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

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int c = (int)distance(begin(a), min_element(all(a)));

    cout << n - 1 << endl;
    for (int i = c + 1; i < n; ++i) {
        a[i] = a[i - 1] + 1;
        cout << c + 1 << " " << i + 1 << " " << a[c] << " " << a[i] << endl;
    }
    for (int i = c - 1; i >= 0; --i) {
        a[i] = a[i + 1] + 1;
        cout << c + 1 << " " << i + 1 << " " << a[c] << " " << a[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    exit(0);
}