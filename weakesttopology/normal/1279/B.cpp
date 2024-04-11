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
        int n; ll s; cin >> n >> s;
        vll a(n); READ(a);

        ll sum = 0;
        int x = -1;
        ll skip = 0;
        for (int i = 0; i < n && sum - skip <= s; ++i)
        {
            sum += a[i];

            if ((x == -1 || a[x] < a[i]) && sum - a[i] <= s)
            {
                x = i;
                skip = a[i];
            }
        }

        if (sum <= s)
            cout << 0 << endl;
        else
            cout << x + 1 << endl;
    }
    exit(0);
}