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
#define SZ(X) (int)X.size();

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
        int n; cin >> n;
        vll a(n); READ(a);

        ll T = 0;
        ll sum = 0;
        ll M = -LINF;
        for (int i = 0; i < n; ++i)
            T += a[i];

        for (int i = 0; i < n - 1; ++i)
        {
            sum += a[i];
            M = max(sum, M);
            sum = max(sum, 0LL);
        }

        sum = 0;
        for (int i = n - 1; i > 0; --i)
        {
            sum += a[i];
            M = max(sum, M);
            sum = max(sum, 0LL);
        }

        string ans = "NO";
        if (M < T)
            ans = "YES";
        cout << ans << endl;
    }
    exit(0);
}