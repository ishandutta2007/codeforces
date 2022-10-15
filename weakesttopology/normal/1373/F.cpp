
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

    vector<ll> a(n), b(n);

    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    if (accumulate(all(a), 0LL) > accumulate(all(b), 0LL)) return "NO";

    vector<ll> prefix_sum(2 * n);

    for (int i = 0; i < 2 * n; ++i)
    {
        prefix_sum[i] = b[i % n] - a[i % n];
        if (i > 0) prefix_sum[i] += prefix_sum[i - 1];
    }

    auto suffix_min = prefix_sum;

    for (int i = 2 * (n - 1); i >= 0; --i)
    {
        suffix_min[i] = min(suffix_min[i], suffix_min[i + 1]);
    }

    bool good = true;

    for (int i = 0; i < n; ++i)
    {
        ll balance = b[(i + n - 1) % n] + suffix_min[i];
        if (i > 0) balance -= prefix_sum[i - 1];
        if (balance < 0)
        {
            good = false;
            break;
        }
    }

    return good ? "YES" : "NO";
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}