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
{
    int n, k; cin >> n >> k;

    map<ii, int> H;
    int y = -1, b = -1;

    for (int i = 1; i <= k + 1; ++i)
    {
        cout << "?";
        for (int j = 1; j <= k + 1; ++j)
        {
            if (i == j)
                continue;

            cout << " " << j;
        }
        cout << endl << flush;

        int x, a; cin >> x >> a;
        H[mp(x, a)]++;
        if (a > b)
        {
            y = x;
            b = a;
        }
    }

    cout << "! " << H[mp(y, b)] << endl;

    exit(0);
}