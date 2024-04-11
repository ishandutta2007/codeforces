#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

string solve() {
    array<int, 4> s;
    for (auto& x : s) cin >> x;
    auto a = s;
    sort(all(a));

    sort(all(s) - 2);
    sort(2 + all(s));

    return (a[2] == s[1] && a[3] == s[3]) || (a[2] == s[3] && a[3] == s[1]) ? "YES" : "NO";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) cout << solve() << endl;

    exit(0);
}