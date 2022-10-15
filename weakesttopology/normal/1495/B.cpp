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

    vector<int> p(n);
    for (auto& x : p) cin >> x;

    vector<array<int, 2>> up(n), down(n);

    for (int i = 1; i < n; ++i)
    {
        auto& v = p[i - 1] < p[i] ? down : up;
        v[i][0] = v[i - 1][0] + 1;
    }

    for (int i = n - 2; i >= 0; --i)
    {
        auto& v = p[i + 1] < p[i] ? down : up;
        v[i][1] = v[i + 1][1] + 1;
    }

    vector<int> prefix(n), suffix(n);
    for (int i = 0; i + 1 < n; ++i)
    {
        prefix[i + 1] = max({prefix[i], up[i][0], up[i][1]});
    }
    for (int i = n - 1; i > 0; --i)
    {
        suffix[i - 1] = max({suffix[i], up[i][0], up[i][1]});
    }
    for (int i = 0; i < n; ++i)
    {
        prefix[i] = max(prefix[i], up[i][0]);
        suffix[i] = max(suffix[i], up[i][1]);
    }

    int res = 0;
 
    for (int i = 1; i + 1 < n; ++i)
    {
        bool current = down[i][0] == down[i][1] && down[i][0] % 2 == 0 && down[i][0];
        bool others = max(prefix[i - down[i][0]], suffix[i + down[i][1]]) < down[i][0];
        res += current && others;
    }

    cout << res << endl;

    exit(0);
}