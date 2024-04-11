#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i = 0; i < (int)X.size(); ++i) cin >> X[i];
#define SZ(X) (int)X.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ull dist(ull x1, ull y1, ull x2, ull y2)
{
    if (x1 > x2)
        swap(x1, x2);
    if (y1 > y2)
        swap(y1, y2);

    return (x2 - x1) + (y2 - y1);
}

int main()
{ _
    ull x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;

    ull xs, ys, t; cin >> xs >> ys >> t;

    vector<pair<ull, ull>> data;

    ull x = x0, y = y0;
    while (dist(xs, ys, x, y) <= ull(3) * 1e16)
    {
        data.pb({x, y});
        x = x * ax + bx;
        y = y * ay + by;
    }
    sort(ALL(data));

    int ans = 0;
    for (int i = 0; i < SZ(data); ++i)
    {
        ull z = dist(xs, ys, data[i].f, data[i].s);
        int c = 1;

        for (
            int j = i + 1;

            j < SZ(data) &&
            z + dist(data[j - 1].f, data[j - 1].s, data[j].f, data[j].s) <= t;

            z += dist(data[j - 1].f, data[j - 1].s, data[j].f, data[j].s),
            j++, c++
        );

        if (z <= t)
            ans = max(ans, c);
    }

    for (int i = SZ(data) - 1; i >= 0; --i)
    {
        ull z = dist(xs, ys, data[i].f, data[i].s);
        int c = 1;

        for (
            int j = i - 1;

            j >= 0 &&
            z + dist(data[j + 1].f, data[j + 1].s, data[j].f, data[j].s) <= t;

            z += dist(data[j + 1].f, data[j + 1].s, data[j].f, data[j].s),
            j--, c++
        );

        if (z <= t)
            ans = max(ans, c);
    }

    cout << ans << endl;

    exit(0);
}