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

bool chmax(auto& x, auto y){ return x < y ? x = y, true : false; }

constexpr int nmax = 2e3;

int a[nmax][nmax];

ll hit[nmax][nmax];

int main()
{ _
    int n; cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    auto valid = [&](int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; };

    {
        for (int i = 0; i < n; ++i)
        {
            ll sum = 0LL;

            for (int x = i, y = 0; valid(x, y); x -= 1, y += 1)
                sum += a[x][y];
            for (int x = i, y = 0; valid(x, y); x -= 1, y += 1)
                hit[x][y] += sum;
        }
        for (int i = 1; i < n; ++i)
        {
            ll sum = 0LL;

            for (int x = n - 1, y = i; valid(x, y); x -= 1, y += 1)
                sum += a[x][y];
            for (int x = n - 1, y = i; valid(x, y); x -= 1, y += 1)
                hit[x][y] += sum;
        }
    }
    {
        for (int i = 0; i < n; ++i)
        {
            ll sum = 0LL;

            for (int x = i, y = 0; valid(x, y); x += 1, y += 1)
                sum += a[x][y];
            for (int x = i, y = 0; valid(x, y); x += 1, y += 1)
                hit[x][y] += sum;
        }
        for (int i = 1; i < n; ++i)
        {
            ll sum = 0LL;

            for (int x = 0, y = i; valid(x, y); x += 1, y += 1)
                sum += a[x][y];
            for (int x = 0, y = i; valid(x, y); x += 1, y += 1)
                hit[x][y] += sum;
        }
    }

    ll maxhit[2] = { -1LL, -1LL };

    int x[2], y[2];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            hit[i][j] -= a[i][j];

            int t = (i + j) % 2;

            if (chmax(maxhit[t], hit[i][j])) x[t] = i, y[t] = j;
        }
    }

    ll ans = maxhit[0] + maxhit[1];

    cout << ans << endl;

    for (int t = 0; t < 2; ++t) cout << x[t] + 1 << " " << y[t] + 1 << " ";
    cout << endl;

    exit(0);
}