#include "bits/stdc++.h"

using namespace std;

#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int query(int i)
{
    cout << "? " << i + 1 << endl;
    int res;
    cin >> res;
    return res;
}

int d(int i)
{
    return query(i) < query(i + 1) ? +1 : -1;
}

int main()
{
    int n;
    cin >> n;

    int res = -1;

    if (n == 1)
    {
        res = 0;
    }
    else if (n == 2)
    {
        res = query(0) < query(1) ? 0 : 1;
    }
    else
    {
        int l = -1, r = n - 1;
        while (l + 1 < r)
        {
            int m = l + (r - l) / 2;
            if (d(m) == -1) l = m;
            else r = m;
        }
        res = r;
    }

    cout << "! " << res + 1 << endl;

    exit(0);
}