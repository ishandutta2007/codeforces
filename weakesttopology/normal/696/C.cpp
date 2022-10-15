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
#define SZ(X) (int)X.size()

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

ll modpower(ll a, ull p, ll MOD)
{
    ll r = 1;

    while (p)
    {
        if (p & 1)
            r = (r * a) % MOD;

        a = (a * a) % MOD;
        p >>= 1;
    }

    return r;
}

int main()
{ _
    int k; cin >> k;
    vll a(k); READ(a);

    const ll MOD = 1e9 + 7;

    ll n = 1, r = 1;
    for (int i = 0; i < k; ++i)
    {
        n = (n * (a[i] % (MOD - 1))) % (MOD - 1);
        r = min(r, a[i] % 2);
    }

    n = (n - 1 + MOD - 1) % (MOD - 1);

    ll q = modpower(2, n, MOD);

    ll p = (q + (r ? -1 : 1) + MOD) % MOD;

    p = (p * modpower(3, MOD - 2, MOD)) % MOD;

    cout << p << "/" << q << endl;

    exit(0);
}