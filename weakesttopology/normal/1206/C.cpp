#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define mp(x, y) make_pair(x, y)
#define READ(X) for (int i = 0; i < (int)X.size(); ++i) cin >> X[i];
#define ALL(X) X.begin(), X.end()

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

    if (n % 2 == 0)
    {
        cout << "NO\n";
        exit(0);
    }
    else
        cout << "YES\n";

    vi ans(2 * n);
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            ans[i] = 2 * i + 1;
            ans[i + n] = 2 * i + 2;
        }
        else
        {
            ans[i] = 2 * i + 2;
            ans[i + n] = 2 * i + 1;
        }
    }

    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    exit(0);
}