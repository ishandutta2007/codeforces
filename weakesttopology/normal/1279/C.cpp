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
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        vll a(n), b(m), I(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            a[i]--;
            I[a[i]] = i;
        }
        for (int j = 0; j < m; ++j)
        {
            cin >> b[j];
            b[j]--;
        }

        ll sum = 0;
        ll M = 0;
        for (ll j = 0; j < m; ++j)
        {
            sum += 2 * (I[b[j]] - j) * (I[b[j]] > M) + 1;
            M = max(M, I[b[j]]);
        }

        cout << sum << endl;
    }
    exit(0);
}