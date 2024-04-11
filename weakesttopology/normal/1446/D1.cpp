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

    int K = 100;

    vector a(n, 0), freq(K, 0);

    int d = 0;

    for (auto& x : a)
    {
        cin >> x; --x;
        if (++freq[x] > freq[d]) d = x;
    }

    int N = 2 * n + 1;

    vector vmp(N, 0);

    int* mp = &vmp[n];

    auto find = [&](int x)
    {
        fill(all(vmp), INF);

        int res = 0;

        mp[0] = -1;

        for (int i = 0, sum = 0; i < n; ++i)
        {
            sum += a[i] == d ? +1 : a[i] == x ? -1 : 0;
            if (mp[sum] == INF) mp[sum] = i;
            else res = max(res, i - mp[sum]);
        }

        return res;
    };

    int ans = 0;

    for (int x = 0; x < K; ++x) if (freq[x] > 0 && x != d)
        ans = max(ans, find(x));

    cout << ans << endl;

    exit(0);
}