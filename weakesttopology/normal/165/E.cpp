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
    int p = 24;

    vi a(n, 0);
    READ(a);

    vi F(1 << p, -1);
    for (int i = 0; i < n; ++i)
        F[a[i]] = a[i];

    for (int i = 0; i < p; ++i)
        for (int x = 0; x < 1 << p; ++x)
            if (x & (1 << i))
                F[x] = max(F[x], F[x ^ (1 << i)]);

    for (int i = 0; i < n; ++i)
        cout << F[(~a[i]) & ((1 << p) - 1)] << " ";
    cout << endl;

    exit(0);
}