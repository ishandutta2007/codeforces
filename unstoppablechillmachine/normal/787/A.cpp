#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF = 1e9 + 10;
ll const BINF = 1e18 + 10;
int const MAXN = 1e6 + 10;
ld const EPS = 1e-6;

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

map<int, int> mp;
int a, b, c, d;

int main()
{
    //freopen("bacteria.in","r",stdin);
    //freopen("bacteria.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> a >> b >> c >> d;
    while(b <= 1e5)
    {
        mp[b]++;
        b += a;
    }

    while(d <= 1e5)
    {
        mp[d]++;
        d += c;
    }

    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        if (it -> sec > 1)
        {
            cout << it -> f;
            exit(0);
        }
    }

    cout << -1;

    return 0;
}