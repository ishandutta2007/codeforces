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

void solve()
{
    int n; cin >> n;

    vector a(n, 0);

    ll S[2] = { 0LL, 0LL };

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        S[i & 1] += a[i];
    }

    for (int i = (S[0] > S[1]); i < n; i += 2) a[i] = 1;

    for (int i = 0; i < n; ++i) cout << a[i] << "\n "[i + 1 < n];
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}