#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define mp(x, y) make_pair(x, y)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
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
    int n, m; cin >> n >> m;
    vll a(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int j = 0; j < m; ++j)
        cin >> b[j];

    ll x; cin >> x;

    vll Sa(n), Sb(m); Sa[0] = a[0], Sb[0] = b[0];
    for (int i = 1; i < n; ++i)
        Sa[i] = Sa[i - 1] + a[i];
    for (int j = 1; j < m; ++j)
        Sb[j] = Sb[j - 1] + b[j];

    vector<pair<ll, int>> A, B;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
        {
            ll sum = Sa[j];
            if (i > 0)
                sum -= Sa[i - 1];
            A.pb({sum, j - i + 1});
        }
    for (int i = 0; i < m; ++i)
        for (int j = i; j < m; ++j)
        {
            ll sum = Sb[j];
            if (i > 0)
                sum -= Sb[i - 1];
            B.pb({sum, j - i + 1});
        }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vi Bmaxes(B.size());
    Bmaxes[0] = B[0].s;
    for (int i = 1; i < (int)B.size(); ++i)
        Bmaxes[i] = max(Bmaxes[i - 1], B[i].s);

    int M = 0;
    for (auto p : A)
    {
        auto end = lower_bound(B.begin(), B.end(), mp(x / p.f + 1, 0));

        if (end == B.begin())
            continue;

        end = prev(end);

        M = max(M, p.s * Bmaxes[distance(B.begin(), end)]);
    }

    cout << M << endl;

    exit(0);
}