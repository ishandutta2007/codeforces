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
    int n; cin >> n;

    vector<int> a(n);

    for (auto& x : a) cin >> x;

    ll sum = a[0];

    for (int i = 0; i < n - 1; ++i)
    {
        ll delta = a[i + 1] - a[i];
        if (delta < 0) sum += delta;
    }

    string ans = sum >= 0 ? "YES" : "NO";

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}