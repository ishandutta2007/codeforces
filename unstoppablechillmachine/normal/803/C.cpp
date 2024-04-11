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

ll n, k, max1;
set<ll> st;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> k;
    if (k > MAXN || k * (k + 1) / 2 > n)
    {
        cout << -1;
        exit(0);
    }

    for(int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            st.insert(i);
            st.insert(n / i);
        }
    }

    for(set<ll>::iterator it = st.begin(); it != st.end(); it++)
    {
        if ((*it) * k * (k + 1) / 2 <= n) max1 = *it;
        else break;
    }

    forn(i, k - 1)
    {
        cout << max1 * i << " ";
        n -= max1 * i;
    }

    cout << n;


    return 0;
}