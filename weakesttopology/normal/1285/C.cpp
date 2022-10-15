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
    ll X; cin >> X;
    ll Y = X;

    map<ll, int> H;
    set<ll> F;

    while (X % 2 == 0)
    {
        H[2]++;
        X /= 2;

        F.insert(2);
    }

    for (ll p = 3; p * p <= X; ++p)
    {
        while (X % p == 0)
        {
            H[p]++;
            X /= p;

            F.insert(p);
        }
    }

    if (X != 1)
    {
        H[X]++;
        F.insert(X);
    }

    vi f;
    for (auto x : F)
        f.pb(x);

    ll M = Y;

    int N = f.size();
    for (int mask = 1; mask < 1 << (N + 1); ++mask)
    {
        ll a = 1;
        for (int i = 0; i < N; ++i)
        {
            if (1 << i & mask)
            {
                for (int x = 0; x < H[f[i]]; ++x)
                    a *= f[i];
            }
        }

        M = min(M, max(a, Y / a));
    }

    cout << M << " " << Y / M << endl;

    exit(0);
}