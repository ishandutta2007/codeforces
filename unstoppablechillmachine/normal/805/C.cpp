#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF = 1e9 + 10;
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

int n, now, from, ans;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    now = n;
    from = 1;
    for(int sum = 2; sum < n; sum++)
    {
        if ((now + from) % (n + 1) == 0)
        {
            from = now;
            now= n + 2 - now;
            ans++;
        }
        else
        {
            from = now;
            now = n + 1 - now;
        }
    }

    cout << ans;

    return 0;
}