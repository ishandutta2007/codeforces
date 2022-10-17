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

ll n, arr[MAXN], pref[MAXN], sum1, sum2;
map<ll, ll> mp, t;

int main()
{
    //freopen("bacteria.in","r",stdin);
    //freopen("bacteria.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    forn(i, n)
    {
        cin >> arr[i];
        pref[i] = pref[i - 1] + arr[i];
        mp[arr[i]]++;
    }
    if(pref[n] % 2 == 1)
    {
        cout << "NO";
        exit(0);
    }

    if (mp[pref[n] / 2] > 0)
    {
        cout << "YES";
        exit(0);
    }

    forn(i, n - 1)
    {

        mp[arr[i]]--;
        t[arr[i]]++;
        sum1 = pref[i];
        sum2 = pref[n] - sum1;
        //cout << sum1 << " " << sum2 << endl;
        if (sum1 == sum2)
        {
            cout << "YES";
            exit(0);
        }
        if (sum1 < sum2)
        {
            if ((sum2 - sum1) % 2 == 0 && mp[(sum2 - sum1) / 2] > 0)
            {
                cout << "YES";
                exit(0);
            }
        }
        if (sum1 > sum2)
        {
            if ((sum1 - sum2) % 2 == 0 && t[(sum1 - sum2) / 2] > 0)
            {
                cout << "YES";
                exit(0);
            }
        }
    }

    cout << "NO";


    return 0;
}