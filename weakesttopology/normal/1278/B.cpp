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

bool check(ll h, ll n)
{
    return (n * (n + 1)) / 2 >= h;
}

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        ll a, b; cin >> a >> b;

        ll h = abs(a - b), ans = -1;

        for (ll z = h + 1; z >= 1; z /= 2)
            while (not check(h, ans + z))
                ans += z;

        ans += 1;

        while (h % 2 != (ans * (ans + 1)) / 2 % 2)
            ans += 1;

        cout << ans << endl;
    }
    exit(0);
}