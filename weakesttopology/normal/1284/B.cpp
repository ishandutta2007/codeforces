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
    int n; cin >> n;

    vll MAX(1e6 + 10, 0);
    vll S(n);
    vi X(n, 0);
    ll z = 0;
    for (int i = 0; i < n; ++i)
    {
        int l; cin >> l;

        ll a = INF, b = -1;
        for (int j = 0; j < l; ++j)
        {
            ll s; cin >> s;
            if (s > a && not X[i])
            {
                X[i] = 1;
                z++;
            }
            a = min(a, s);
            b = max(b, s);
        }
        S[i] = a;

        if (not X[i])
            MAX[b]++;
    }

    for (int i = 1e6 + 2; i >= 0; --i)
        MAX[i] += MAX[i + 1];

    ll sum = 0;
    for (int i = 0; i < n; ++i)
        sum += (X[i] ? ll(n) : z + MAX[S[i] + 1]);

    cout << sum << endl;

    exit(0);
}