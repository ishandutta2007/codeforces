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
    int n;
    cin >> n;

    vector<int> f(n);
    for (auto& x : f)
    {
        cin >> x;
        --x;
    }

    auto h = f;
    sort(all(h)), h.erase(unique(all(h)), end(h));
    auto get = [&](auto y)
    {
        return (int)distance(begin(h), lower_bound(all(h), y));
    };

    int m = size(h);

    bool good = true;

    vector<int> g(n, -1);
    for (int y = 0; y < m; ++y) g[h[y]] = y;

    for (int x = 0; x < n; ++x)
    {
        if (g[x] != -1 && h[g[x]] != f[x])
        {
            good = false;
            break;
        }
        else if (g[x] == -1) g[x] = get(f[x]);
    }

    if (not good) cout << -1 << endl;
    else
    {
        cout << m << endl;
        for (int x = 0; x < n; ++x) cout << g[x] + 1 << "\n "[x + 1 < n];
        for (int y = 0; y < m; ++y) cout << h[y] + 1 << "\n "[y + 1 < m];
    }

    exit(0);

}