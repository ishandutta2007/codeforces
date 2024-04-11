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
    vi a(n); READ(a);

    vi l(n), r(n);

    stack<int> S;

    for (int i = 0; i < n; ++i)
    {
        while (not S.empty() && a[S.top()] >= a[i])
            S.pop();

        if (S.empty())
            l[i] = -1;
        else
            l[i] = S.top();

        S.push(i);
    }

    S = stack<int>();

    for (int i = n - 1; i >= 0; --i)
    {
        while (not S.empty() && a[S.top()] >= a[i])
            S.pop();

        if (S.empty())
            r[i] = n;
        else
            r[i] = S.top();

        S.push(i);
    }

    vi f(n, 0);

    for (int i = 0; i < n; ++i)
        f[r[i] - l[i] - 2] = max(f[r[i] - l[i] - 2], a[i]);

    for (int i = n - 2; i >= 0; --i)
        f[i] = max(f[i], f[i + 1]);

    for (auto x : f)
        cout << x << " ";
    cout << endl;

    exit(0);
}