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

void solve()
{
    int n, m; cin >> n >> m;

    vector a(n, vector(m, 0));

    for (auto& v : a)
    {
        for (int j = 0; j < m; ++j)
        {
            char c; cin >> c;
            v[j] = c - '0';
        }
    }

    vector op(0, tuple(0, 0, 0, 0, 0, 0));

    auto apply = [&](int x1, int y1, int x2, int y2, int x3, int y3)
    {
        a[x1][y1] ^= 1, a[x2][y2] ^= 1, a[x3][y3] ^= 1;
        op.emplace_back(x1, y1, x2, y2, x3, y3);
    };

    auto fix_single = [&](int i, int j)
    {
        if (a[i][j] == 0) return;
        apply(i, j, i + 1, j, i, j + 1);
    };

    for (int i = 0; i + 2 < n; ++i)
        for (int j = 0; j + 2 < m; ++j) fix_single(i, j);

    using ii = pair<int, int>;

    auto fix_square = [&](int i, int j)
    {
        int sum = 0;

        ii sq[4];

        for (int s = 0, ptr = 0; s < 2; ++s)
            for (int t = 0; t < 2; ++t)
            {
                sum += a[i + s][j + t];
                sq[ptr++] = pair(i + s, j + t);
            }

        if (sum == 4)
        {
            apply(
                sq[0].first, sq[0].second,
                sq[1].first, sq[1].second,
                sq[2].first, sq[2].second
            );
            sum = 1;
        }

        auto cmp = [&](ii x, ii y)
        {
            return a[x.first][x.second] > a[y.first][y.second];
        };
        sort(all(sq), cmp);

        switch (sum)
        {
            case 1:
                apply(
                    sq[0].first, sq[0].second,
                    sq[1].first, sq[1].second,
                    sq[2].first, sq[2].second
                );
                sort(all(sq), cmp);
                sum = 2;
            case 2:
                apply(
                    sq[3].first, sq[3].second,
                    sq[1].first, sq[1].second,
                    sq[2].first, sq[2].second
                );
                sum = 3;
                sort(all(sq), cmp);
            case 3:
                apply(
                    sq[0].first, sq[0].second,
                    sq[1].first, sq[1].second,
                    sq[2].first, sq[2].second
                );
                sum = 0;
        }
    };

    if (n % 2) fix_square(0, m - 2);

    if (m % 2) fix_square(n - 2, 0);

    for (int i = n % 2; i < n; i += 2) fix_square(i, m - 2);

    for (int j = m % 2; j < m - 2; j += 2) fix_square(n - 2, j);

    for (int i = 0; i < n; ++i) assert(accumulate(all(a[i]), 0) == 0);

    // assert(size(op) <= n * m);

    cout << size(op) << endl;

    for (auto [x1, y1, x2, y2, x3, y3] : op)
    {
        x1++, x2++, x3++, y1++, y2++, y3++;
        cout << x1 << " " << y1 << " ";
        cout << x2 << " " << y2 << " ";
        cout << x3 << " " << y3 << endl;
    }
}

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        debug(t);
        solve();
    }
    exit(0);
}