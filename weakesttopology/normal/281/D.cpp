#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n'
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i = 0; i < (int)X.size(); ++i) cin >> X[i]
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

int main()
{ _
    int n; cin >> n;

    vll s(n); READ(s);

    set<ll> S;

    ll z = 1LL << 32;

    while (SZ(S) <= 1)
    {
        z >>= 1;
        S.clear();
        for (auto x : s)
            S.insert(x & z);
    }

    ll ans = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        ll x = s[i], y = s[i + 1];

        if (not (x & z))
            continue;

        while (i + 1 < n && not (s[i + 1] & z))
        {
            y = max(y, s[i + 1]);
            ans = max(ans, x ^ y);
            ++i;
        }
    }

    for (int i = n - 1; i > 0; --i)
    {
        ll x = s[i], y = s[i - 1];

        if (not (x & z))
            continue;

        while (i - 1 >= 0 && not (s[i - 1] & z))
        {
            y = max(y, s[i - 1]);
            ans = max(ans, x ^ y);
            --i;
        }
    }

    cout << ans << endl;

    exit(0);
}

/*
 * INT_MAX      ~  2 * 1e9  ~ 2^31 - 1
 * LLONG_MAX    ~  9 * 1e18 ~ 2^63 - 1
 * ULLONG_MAX   ~ 18 * 1e18 ~ 2^64 - 1
 *
 * INF  ~ 1.0 * 1e9
 * LINF ~ 4.5 * 1e18
 *
 * CHECK:
 *      OVERFLOW
 *      IF/LOOP CONDITIONS
 *      CREATION OF STL CONTAINERS
 */