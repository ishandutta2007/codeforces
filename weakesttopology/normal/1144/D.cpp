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
    vi a(n); READ(a);

    int p = 0;
    map<int, int> f;
    for (int i = 0; i < n; ++i)
    {
        ++f[a[i]];
        if (f[a[i]] >= f[a[p]])
            p = i;
    }

    int k = n - f[a[p]];
    cout << k << endl;

    for (int i = 1; i < n; ++i)
    {
        if (i == p)
            for (int j = i + 1; j < n; ++j)
                cout << 1 + (a[j] > a[p]) << " " << j + 1 << " " << j << endl;
        if (a[i] == a[p])
            for (int j = i - 1; j >= 0 && a[j] != a[p]; --j)
                cout << 1 + (a[j] > a[p]) << " " << j + 1 << " " << j + 2 << endl;
    }

    exit(0);
}