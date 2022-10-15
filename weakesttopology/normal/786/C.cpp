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

    vector<int> a(n);
    for (auto& x : a)
    {
        cin >> x;
        --x;
    }

    vector<int> vis(n, 0);
    stack<int> stk;

    auto clear = [&]()
    {
        while (not empty(stk))
        {
            vis[stk.top()] = false;
            stk.pop();
        }
    };
    auto solve = [&](int k)
    {
        int uniq = 0, res = 1;
        for (auto x : a)
        {
            if (not vis[x]) uniq += 1;
            if (uniq > k)
            {
                clear();
                uniq = 1, res += 1;
            }
            if (not vis[x])
            {
                vis[x] = true;
                stk.push(x);
            }
        }
        clear();
        return res;
    };

    int magic = min(500, n);

    vector<int> res(n + 1);
    for (int x = 1; x <= magic; ++x) res[x] = solve(x);

    auto dnc = [&](auto& self, int l, int r, int low, int high) -> void
    {
        if (r < l) return;
        int m = l + (r - l) / 2;
        low == high ? res[m] = low : res[m] = solve(m);
        self(self, l, m - 1, low, res[m]);
        self(self, m + 1, r, res[m], high);
    };
    dnc(dnc, magic + 1, n, res[magic], n);

    for (int x = 1; x <= n; ++x) cout << res[x] << "\n "[x < n];

    exit(0);
}