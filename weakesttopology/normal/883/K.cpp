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

void fail()
{
    cout << -1 << endl;
    exit(0);
}

int main()
{ _
    int n; cin >> n;

    vector s(n, 0), g(n, 0);

    for (int i = 0; i < n; ++i) cin >> s[i] >> g[i];

    vector h(n, INF);

    for (int i = 0, cur = INF; i < n; ++i)
    {
        cur = max(s[i], min(cur + 1, s[i] + g[i]));
        h[i] = min(h[i], cur);
    }

    for (int i = n - 1, cur = INF; i >= 0; --i)
    {
        cur = max(s[i], min(cur + 1, s[i] + g[i]));
        h[i] = min(h[i], cur);
    }

    for (int i = 1; i < n; ++i)
        if (abs(h[i] - h[i - 1]) > 1) fail();

    ll ans = 0LL;

    for (int i = 0; i < n; ++i) ans += h[i] - s[i];

    cout << ans << endl;

    for (int i = 0; i < n; ++i) cout << h[i] << " ";
    cout << endl;

    exit(0);
}