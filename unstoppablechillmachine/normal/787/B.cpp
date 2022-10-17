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

int n, m, kol, a, sum1;
pii arr[MAXN];
bool t;
int main()
{
    //freopen("bacteria.in","r",stdin);
    //freopen("bacteria.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> m;
    forn(i, m)
    {
        t = true;
        forn(j, 1e4)
        {
            arr[j].f = 0;
            arr[j].sec = 0;
        }
        sum1 = 0;
        cin >> kol;
        forn(j, kol)
        {
            cin >> a;
            if (a > 0) arr[a].f++;
            else arr[-a].sec++;
        }

        forn(j, 1e4) if (arr[j].f && arr[j].sec) t = false;
        if (t)
        {
            cout << "YES";
            exit(0);
        }
    }
    cout << "NO";
    return 0;
}