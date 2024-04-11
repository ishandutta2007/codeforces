#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll sq(ll x) { return x * x; }

string solve() {
    ll n;
    cin >> n;

    for (auto t : { 2, 4 }) {
        if (n % t) continue;
        ll x = 1, m = n / t;
        for (ll z = m - x; z; z >>= 1) while (sq(x + z) <= m) x += z;
        if (x * x == m) return "YES";
    }

    return "NO";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) cout << solve() << endl;

    exit(0);
}