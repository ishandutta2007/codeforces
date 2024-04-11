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


int n;
vll a, b;

vi vis;

ll end(ll x)
{
    if (vis[x])
        return b[x];

    vis[x] = 1;

    if (x - a[x] < 0 || x - a[x] >= n)
    {
        b[x] = a[x];
        return b[x];
    }
    else if (x - a[x] == 0)
    {
        b[x] = LINF;
        return b[x];
    }
    else if (x - a[x] + a[x - a[x]] < 0 || x - a[x] + a[x - a[x]] >= n)
    {
        b[x] = a[x] + a[x - a[x]];
        return b[x];
    }
    else
    {
        ll next = end(x - a[x] + a[x - a[x]]);
        b[x] = next == LINF ? LINF : a[x] + a[x - a[x]] + next;
        return b[x];
    }
}


int main()
{ _
     cin >> n;
    a.assign(n, LINF);
    b.assign(n, LINF);
    vis.assign(n, 0); vis[0] = 1;

    for (int i = 1; i < n; ++i)
        cin >> a[i];

    for (int i = 1; i < n; ++i)
        end(i);

    for (int i = 1; i <= n - 1; ++i)
        cout << (b[i] == LINF ? -1 : i + b[i]) << endl;

    exit(0);
}