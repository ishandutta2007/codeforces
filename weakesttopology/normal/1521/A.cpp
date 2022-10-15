#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void solve() {
    ll A, B;
    cin >> A >> B;
    if (B == 1) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        ll x = A * (3 * B - 1), y = A, z = x + y;
        cout << x << " " << y << " " << z << endl;
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