#include "bits/stdc++.h"

using namespace std;

#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int query(int x, int y)
{
    x += 1, y += 1;
    cout << "? " << x << " " << y << endl;
    int r; cin >> r;
    return r;
}

int main()
{
    int n; cin >> n;

    vector p(n, n), vis(n, 0);

    vector temp(n, 0); iota(all(temp), 0);

    auto cmp = [&](int i, int j) { return vis[i] < vis[j]; };

    while (sz(temp) > 1)
    {
        for (int k = 1; k < sz(temp); k += 2)
        {
            int i = temp[k - 1], j = temp[k];
            int r1 = query(i, j), r2 = query(j, i);
            if (r1 > r2)
            {
                p[i] = r1;
                vis[i] = 1;
            }
            else
            {
                p[j] = r2;
                vis[j] = 1;
            }
        }
        sort(all(temp), cmp);
        while (not temp.empty() && vis[temp.back()]) temp.pop_back();
    }

    cout << "!";
    for (auto z : p) cout << " " << z;
    cout << endl;
    cout << flush;

    exit(0);
}