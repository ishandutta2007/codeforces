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

int main()
{ _
    int n, q; cin >> n >> q;

    vi r(q), c(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> r[i] >> c[i];
        r[i]--; c[i]--;
    }

    int num_blocks = 0;

    vvi Z(2, vi(n, 0));

    for (int i = 0; i < q; ++i)
    {
        int x = r[i], y = c[i];
        Z[x][y] = !Z[x][y];

        num_blocks += (Z[x][y] ? 1 : -1) * (Z[!x][y] + (y > 0 ? Z[!x][y - 1] : 0) + (y < n - 1 ? Z[!x][y + 1] : 0));

        if (num_blocks)
            cout << "No\n";
        else
            cout << "Yes\n";
    }

    exit(0);
}