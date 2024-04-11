#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll hilbert(int x, int y, int N)
{
    ll d = 0;
    for (int s = N >> 1; s > 0; s >>= 1)
    {
        int rx = (x & s) > 0, ry = (y & s) > 0;
        d += 1LL * s * s * ((3 * rx) ^ ry);
        if (ry == 0)
        {
            if (rx == 1) x = N - 1 - x, y = N - 1 - y;
            swap(x, y);
        }
    }
    return d;
}

int main()
{ _
    int n; cin >> n;

    vector x(n, 0), y(n, 0);

    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    vector h(n, 0LL);

    for (int i = 0; i < n; ++i) h[i] = hilbert(x[i], y[i], 1 << 20);

    vector I(n, 0); iota(all(I), 0);

    sort(all(I), [&h](int i, int j){ return h[i] < h[j]; });

    for (auto i : I) cout << i + 1 << " ";
    cout << endl;

    exit(0);
}