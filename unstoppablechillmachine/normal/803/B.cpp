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

int n, a[MAXN], dp[MAXN];

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
    }

    if (!a[1]) dp[1] = 0;
    else dp[1] = INF;

    for(int i = 2; i <= n; i++)
    {
        if (!a[i]) dp[i] = 0;
        else dp[i] = dp[i - 1] + 1;
    }

    if (!a[n]) dp[n] = 0;
    for(int i = n - 1; i >= 1; i--)
    {
        if (!a[i]) dp[i] = 0;
        else dp[i] = min(dp[i], dp[i + 1] + 1);
    }

    forn(i, n) cout << dp[i] << " ";
    return 0;
}