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

int main()
{ _
    ll n, k; int p; cin >> n >> k >> p;
    vll x(p); READ(x);

    if (2 * k >= n)
    {
        for (int i = 0; i < p; ++i)
        {
            if (x[i] <= 2 * (n - k))
                cout << (x[i] % 2 ? '.' : 'X');
            else
                cout << 'X';
        }
    }
    else if ((n - 2 * k) % 2)
    {
        for (int i = 0; i < p; ++i)
        {
            if (x[i] <= n - 2 * k + 1)
                cout << '.';
            else
                cout << ((n - x[i]) % 2 == 0 && x[i] != n ? '.' : 'X');
        }
    }
    else
    {
        for (int i = 0; i < p; ++i)
        {
            if (x[i] <= n - 2 * k)
                cout << '.';
            else
                cout << ((n - x[i]) % 2 ? '.' : 'X');
        }
    }
    cout << endl;

    exit(0);
}