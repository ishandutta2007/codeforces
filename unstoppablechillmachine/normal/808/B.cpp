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

ll n, k, ans, sum, a, arr[MAXN];

int main()
{
    //freopen("bacteria.in","r",stdin);
    //freopen("bacteria.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> k;
    forn(i, k)
    {
        cin >> a;
        sum += a;
        arr[i] = a;
    }
    ans += sum;

    for(int i = k + 1; i <= n; i++)
    {

        cin >> a;
        arr[i] = a;
        sum += a;
        sum -= arr[i - k];
        ans += sum;
    }

    cout << fixed << setprecision(10) << ld(ans) / ld(n - k + 1);



    return 0;
}