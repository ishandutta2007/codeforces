#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i = 0; i < (int)X.size(); ++i) cin >> X[i];

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 65;

ll C[MAX][MAX];

ll F(ll n, int k)
{
    ll x = 0;

    while ((1LL << (x + 1)) <= n)
        x++;

    ll sum = 0;

    int c = 0;
    while (x >= 0 && c <= k)
    {
        if ((1LL << x) & n)
            sum += C[x][k - c++];
        x--;
    }

    return sum;
}

ll num(ll n, int k)
{
    return F(2 * n, k) - F(n, k);
}

int main()
{ _
    ll m; int k;
    cin >> m >> k;

    memset(C, 0, sizeof C);
    C[0][0] = 1;
    for (int i = 1; i < MAX; ++i)
        for (int j = 0; j <= i; ++j)
            C[i][j] = C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);

    ll z = 0;
    for (ll b = 1e18; b > 0; b /= 2)
        while (z + b <= 1e18 - 1 && num(z + b, k) < m)
            z += b;
    z++;
    cout << z << endl;

    exit(0);
}