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

auto chmax(auto& x, auto y) { x = max(x, y); }

int main()
{ _
    int n, m; cin >> n >> m;

    vector a(n, 0), b(n, 0), c(m, 0), d(m, 0);


    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    for (int j = 0; j < m; ++j) cin >> c[j] >> d[j];

    vector J(m, 0); iota(all(J), 0);
    sort(all(J), [&](int j1, int j2) { return c[j1] > c[j2]; });

    stack<int> stk;
    for (auto j : J)
    {
        while (not stk.empty() && c[j] == c[stk.top()] && d[j] >= d[stk.top()])
            stk.pop();
        if (stk.empty() || d[j] > d[stk.top()]) stk.push(j);
    }

    J.clear();
    while (not stk.empty()) { J.push_back(stk.top()); stk.pop(); }

    auto cmp = [&](int j, int x){ return c[j] < x; };

    const int N = 1e6;

    auto finddy = [&](int i, int dx)
    {
        auto iter = lower_bound(all(J), a[i] + dx, cmp);
        if (iter != J.end()) return max(0, d[*iter] + 1 - b[i]);
        else return 0;
    };

    auto findnext = [&](int i, int dx)
    {
        int dy = finddy(i, dx);

        for (int z = N; z; z >>= 1)
            while (dx + z <= N && finddy(i, dx + z) == dy) dx += z;

        return dx;
    };

    vector mindy(N + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        int dx = 0;
        while (dx <= N)
        {
            int dy = finddy(i, dx);
            dx = findnext(i, dx) + 1;
            chmax(mindy[min(dx - 1, N)], dy);
        }
    }

    for (int dx = N - 1; dx >= 0; --dx)
        chmax(mindy[dx], mindy[dx + 1]);

    int ans = INF;
    for (int dx = 0; dx <= N; ++dx)
        ans = min(ans, dx + mindy[dx]);

    cout << ans << endl;

    exit(0);
}