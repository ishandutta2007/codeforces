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

map<char, int> dx, dy;

pair<int, int> solve()
{
    string s;
    cin >> s;

    int n = size(s);

    int x = 0, y = 0;

    for (int i = 0; i < n; ++i)
    {
        int xbad = x + dx[s[i]], ybad = y + dy[s[i]];
        int xcur = 0, ycur = 0;

        for (int j = 0; j < n; ++j)
        {
            int xnxt = xcur + dx[s[j]], ynxt = ycur + dy[s[j]];
            if (xnxt != xbad || ynxt != ybad)
            {
                xcur = xnxt, ycur = ynxt;
            }
        }

        if (xcur == 0 && ycur == 0) return pair(xbad, ybad);

        x = xbad, y = ybad;
    }

    return pair(0, 0);
}

int main()
{ _
    dx['L'] = -1, dy['L'] = +0;
    dx['R'] = +1, dy['R'] = +0;
    dx['D'] = -0, dy['D'] = -1;
    dx['U'] = -0, dy['U'] = +1;

    int t;
    cin >> t;
    while (t--)
    {
        auto [x, y] = solve();
        cout << x << " " << y << endl;
    }
    exit(0);
}