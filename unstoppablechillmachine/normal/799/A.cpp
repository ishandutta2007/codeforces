#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF = 1e9;
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

int n, m, sum, ans, cnt, k, t, d, sum1, sum2, a;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> t >> k >> d;
    while (a < n)
    {
        a += k;
        sum1 += t;
    }

    a = 0;
    while (a < n)
    {
        sum2++;
        if (sum2 % t == 0) a += k;
        if ((sum2 - d) % t == 0 && sum2 - d > 0) a += k;
    }

    //cout << sum1 << " " << sum2 << endl;
    if (sum2 < sum1) cout << "YES";
    else cout << "NO";






    return 0;
}