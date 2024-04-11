#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

string solve()
{
    ll c[3];
    for (auto& x : c) cin >> x;

    ll a[5];
    for (auto& x : a) cin >> x;

    bool good = true;

    c[0] -= a[0];
    c[1] -= a[1];
    c[2] -= a[2];

    if (*min_element(all(c)) < 0) good = false;

    a[3] -= min(a[3], c[0]);
    a[4] -= min(a[4], c[1]);

    if (a[3] + a[4] > c[2]) good = false;

    return good ? "YES" : "NO";
}

int main()
{ _
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}