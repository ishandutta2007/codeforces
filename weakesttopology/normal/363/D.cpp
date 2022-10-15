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

int n, m, a;
vi b, p;
ll sum;

bool check(int r)
{
    sum = 0;

    for (int i = 0; i < r; ++i)
        sum += max(0, p[i] - b[n - r + i]);

    return sum <= a;
}

int main()
{ _
    cin >> n >> m >> a;

    b.assign(n, 0); READ(b);
    p.assign(m, 0); READ(p);

    sort(ALL(b));
    sort(ALL(p));

    int r = 0;
    for (int z = min(n, m); z > 0; z /= 2)
        while (r + z <= min(n, m) && check(r + z))
            r += z;

    ll total = 0;
    for (int i = 0; i < r; ++i)
        total += p[i];

    cout << r << " " << max(total - ll(a), 0LL) << endl;

    exit(0);
}