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
    int n; cin >> n;
    const int MAX = 2 * 1e5 + 2;
    vi x(MAX, 0);
    for (int i = 0; i < n; ++i)
    {
        int c; cin >> c;
        x[c]++;
    }

    vi m(MAX, 0);
    m[0] = min(x[0], 1);
    m[1] = min(x[0] + x[1], 1);
    m[2] = min(x[0] + x[1] + x[2], 1);
    for (int i = 3; i < MAX; ++i)
        m[i] = min(
            m[i - 1] + min(x[i], 1),
            min(
                m[i - 2] + min(x[i] + x[i - 1], 1),
                m[i - 3] + min(x[i] + x[i - 1] + x[i - 2], 1)
            )
        );

    int c = 0;
    for (int i = 0; i < MAX; ++i)
    {
        if (x[i] > 0)
        {
            c++;
            if (i + 1 < MAX)
                x[i + 1] += min(x[i] - 1, 1);
        }
        else if (i + 1 < MAX && x[i + 1])
        {
            c++;
            x[i + 1]--;
        }
    }

    cout << m.back() << " " << c << endl;

    exit(0);
}