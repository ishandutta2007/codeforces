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
#define READ(X) for (int i_ = 0; i_ < (int)X.size(); ++i_) cin >> X[i_]
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

int sum_digits(int x)
{
    int sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

int num_digits(int x)
{
    int num = 0;

    while (x)
    {
        num++;
        x /= 10;
    }

    return num;
}

ll least_x(int sum)
{
    ll x = sum % 9;

    while (sum >= 9)
    {
        x = 10 * x + 9;
        sum -= 9;
    }

    return x;
}

int main()
{ _
    int t; cin >> t;

    while (t--)
    {
        int n, k; cin >> n >> k;

        vi S(151, INF);

        for (int x = 0; x + k < 1e5; ++x)
        {
            int sum = 0;
            for (int i = x; i <= x + k; ++i)
                sum += sum_digits(i);

            if (sum <= 150)
                S[sum] = min(x, S[sum]);
        }

        ll ans = LINF;

        for (int j = 0; j <= 150; ++j)
        {
            if (S[j] == INF)
                continue;

            int key = S[j];
            int sum = j;

            if (sum <= n && (n - sum) % (k + 1) == 0)
            {
                ll x = least_x((n - sum) / (k + 1));
                for (int i = 0; i < num_digits(key + k); ++i, x *= 10);
                x += key;

                ans = min(ans, x);
            }
        }

        if (ans == LINF)
            ans = -1;

        cout << ans << endl;
    }
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