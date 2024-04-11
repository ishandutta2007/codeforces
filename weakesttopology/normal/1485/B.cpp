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
    int n, q;
    ll k;
    cin >> n >> q >> k;

    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    vector<ll> diff(n, 0);

    for (int i = 1; i < n - 1; ++i)
    {
        diff[i] = a[i + 1] - a[i - 1] - 2;
        diff[i] += diff[i - 1];
    }

    auto query = [&](int l, int r) { return diff[r] - diff[l - 1]; };

    for (int z = 0; z < q; ++z)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;

        ll res = -1;

        if (l == r)
        {
            res = k - 1;
        }
        else if (r == l + 1)
        {
            res = (k - a[l] - 1) + (a[r] - 2);
        }
        else
        {
            res = query(l + 1, r - 1);
            res += (a[l + 1] - 2) + (k - a[r - 1] - 1);
        }

        cout << res << endl;
    }

    exit(0);
}