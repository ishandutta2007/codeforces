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
    int n, m, p; cin >> n >> m >> p;

    vi a(n); READ(a);
    map<int, int> H;
    set<int> C;
    for (int i = 0; i < m; ++i)
    {
        int b; cin >> b;
        H[b]++;
        C.insert(b);
    }

    set<int> S;

    for (int i = 0; i < min(p, n); ++i)
    {
        map<int, int> G;
        int c = 0;

        for (int j = i; j < n; j += p)
        {
            if (ll(j) < ll(i) + ll(m) * ll(p))
            {
                c -= (H[a[j]] > 0) * (G[a[j]] == H[a[j]]);
                G[a[j]]++;
                c += G[a[j]] == H[a[j]];
            }
            else
            {
                int q = j - m * p;

                c -= G[a[q]] == H[a[q]];
                G[a[q]]--;
                c += (H[a[q]] > 0) * (G[a[q]] == H[a[q]]);

                c -= (H[a[j]] > 0) * (G[a[j]] == H[a[j]]);
                G[a[j]]++;
                c += G[a[j]] == H[a[j]];
            }

            if (c == (int)C.size())
                S.insert(j - (m - 1) * p);
        }
    }

    cout << S.size() << endl;
    for (auto q : S)
        cout << q + 1 << " ";
    cout << endl;

    exit(0);
}