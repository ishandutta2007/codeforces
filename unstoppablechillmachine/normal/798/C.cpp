#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF = 1000000000;
ll const BINF = 1000000000000000000;
int const MAXN = 1e6 + 10;
ld const EPS = 1e-13;

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

ll n, a[MAXN], a1, a2, gc, cnt;

ll gcd(ll a, ll b)
{
    ll ost = 0;
    while (b != 0)
    {
        ost = a % b;
        a = b;
        b = ost;
    }
    return a;
}

bool check()
{
    forn(i, n)
    {
        if ((a[i] + INF) % 2 != 0) return false;
    }
    return true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    forn(i, n)
    {
        cin >> a[i];
        if (n == 1) gc = a[i];
        else gc = gcd(a[i], gc);
    }

    if (gc > 1)
    {
        cout << "YES" << endl << 0;
        exit(0);
    }

    forn(i, n)
    {
        if ((a[i] + INF) % 2 != 0)
        {
            a1 = a[i] - a[i + 1];
            a2 = a[i] + a[i + 1];
            a[i] = a1;
            a[i + 1] = a2;
            cnt++;
        }
        if ((a[i] + INF) % 2 != 0)
        {
            a1 = a[i] - a[i + 1];
            a2 = a[i] + a[i + 1];
            a[i] = a1;
            a[i + 1] = a2;
            cnt++;
        }
        if (i == n - 1) a[n + 1] = a[i];
    }



    cout << "YES" << endl << cnt;



    return 0;
}