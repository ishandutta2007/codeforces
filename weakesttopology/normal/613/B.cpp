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

int main()
{ _
    int n; cin >> n;

    ll A, cf, cm, m; cin >> A >> cf >> cm >> m;

    vector a(n, 0LL);

    for (int i = 0; i < n; ++i) cin >> a[i];

    vector I(n, 0); iota(all(I), 0);
    sort(all(I), [&a](int i, int j){ return a[i] < a[j]; });

    sort(all(a));

    auto prefix = a;

    for (int i = 1; i < n; ++i) prefix[i] += prefix[i - 1];

    auto find = [&](ll cost)
    {
        int i = 0;
        for (int z = n; z; z >>= 1)
            while (i + z < n && a[i + z] * (i + z + 1) - prefix[i + z] <= cost) i += z;
        return i;
    };

    auto fill = [&](int i, ll m)
    {
        if (i < 0) return A * cm;
        ll cost = a[i] * (i + 1) - prefix[i];
        return cm * min(A, a[i] + (m - cost) / (i + 1));
    };

    int idx = n;

    ll ans = fill(find(m), m), suffix = 0LL, left = m;

    for (int i = n - 1; i >= 0 && A - a[i] <= m; --i)
    {
        suffix += cf, m -= A - a[i];

        if (ll x = suffix + fill(min(find(m), i - 1), m); ans < x)
            ans = x, left = m, idx = i;
    }

    vector rec(n, 0LL);

    for (int i = n - 1; i >= idx; --i) rec[I[i]] = A;

    for (int i = 0; i < idx; ++i) rec[I[i]] = a[i];

    int jdx = min(find(left), idx - 1);

    if (jdx >= 0)
    {
        ll cost = a[jdx] * (jdx + 1) - prefix[jdx];

        ll cut = a[jdx] + (left - cost) / (jdx + 1);

        for (int i = 0; i <= jdx; ++i) rec[I[i]] = cut;
    }

    cout << ans << endl;

    for (auto x : rec) cout << x << " ";
    cout << endl;

    exit(0);
}