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
    int n, k; cin >> n >> k;

    vector<int> h(n);

    for (auto& x : h) cin >> x;

    string ans = "YES";

    int l = h[0], r = h[0];

    for (int i = 1; i < n; ++i)
    {
        l = max(h[i], l - (k - 1));
        r = min(h[i] + k - 1, r + (k - 1));

        if (r < l) return "NO";
    }

    return l == h[n - 1] ? "YES" : "NO";
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}