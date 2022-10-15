#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int solve()
{
    int n, k; cin >> n >> k;

    vector a(n, 0);
    for (auto& x : a) cin >> x;

    if (k == 1)
    {
        a.erase(unique(all(a)), a.end());
        if (sz(a) == 1) return 1;
        else return -1;
    }

    int ans = 0;

    vector v(n, 0);
    while (accumulate(all(a), 0))
    {
        for (int i = 0, h = 0, ct = 0; i < n && ct < k; ++i)
        {
            if (a[i] > h || i == 0) ct += 1;
            v[i] = h = a[i];
            a[i] = 0;
        }
        for (int i = 1; i < n; ++i)
            if (v[i] == 0) v[i] = v[i - 1], a[i] -= v[i];
        v.assign(n, 0);
        ++ans;
    }

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}