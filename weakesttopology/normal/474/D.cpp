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

ll mod = 1e9 + 7;

int main()
{ _
    int t, k; cin >> t >> k;
    const int MAX = 1e5;

    vi ans(MAX + 1, 1);
    ans[0] = 1;

    for (int x = k; x <= MAX; ++x)
        ans[x] = (ans[x - 1] + ans[x - k]) % mod;

    for (int x = 1; x <= MAX; ++x)
        ans[x] = (ans[x] + ans[x - 1]) % mod;

    while (t--)
    {
        int a, b; cin >> a >> b;

        cout << ((ans[b] - ans[a - 1]) % mod + mod) % mod << endl;
    }
    exit(0);
}