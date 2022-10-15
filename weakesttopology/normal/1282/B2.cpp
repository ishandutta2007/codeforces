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
        int n, p, k; cin >> n >> p >> k;
        vi a(n); READ(a);
        sort(ALL(a));

        vi sum(k - 1, 0); sum[0] = a[0];

        int M = a[0] <= p;

        for (int i = 1; i < k - 1; ++i)
        {
            sum[i] = sum[i - 1] + a[i];
            if (sum[i] <= p)
                M = i + 1;
        }

        for (int i = k - 1; i < 2 * k - 1 && i < n && a[i] <= p; ++i)
        {
            int m = 0;
            int q = p;

            for (int j = i; j < n && a[j] <= q; q -= a[j], j += k, m += k);

            auto iter = upper_bound(sum.begin(), sum.begin() + i - (k - 1), q);
            m += distance(sum.begin(), iter);

            M = max(M, m);
        }
        cout << M << endl;
    }
    exit(0);
}