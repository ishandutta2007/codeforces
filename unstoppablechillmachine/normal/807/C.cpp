#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF = 1e9 + 7;
ll const BINF = 1e18 + 10;
int const MAXN = 1e6 + 10;
ld const EPS = 1e-9;

#define f first
#define sec second
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mk make_pair
#define fro for
#define itn int
#define forn(i, n) for (int i = 1; i <= n; i++)
#define fore(i, n) for (int i = 0; i < n; i++)

ll t, l, r, mid, a, b, c, d, c1, d1, min1;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> t;
    forn(k, t)
    {
        min1 = BINF;
        cin >> a >> b >> c >> d;
        if (!a && !c)
        {
            cout << 0 << endl;
            continue;
        }
        if (d == 1 && (a != b))
        {
            cout << -1 << endl;
            continue;
        }

        if (c == 0 && a != 0)
        {
            cout << -1 << endl;
            continue;
        }
        l = 0;
        r = INF;
        while (r - l > 1)
        {
            mid = (l + r) / 2;
            c1 = c * mid;
            d1 = d * mid;
            if (b > d1 || a > c1) l = mid;
            else
            {
                if (d1 - b < c1 - a) l = mid;
                else
                {
                    min1 = min(min1, d1 - b);
                    r = mid;
                }

            }
        }
        if (min1 >= BINF)
        {
            cout << -1 << endl;
            continue;
        }
        cout << min1 << endl;
    }



    return 0;
}