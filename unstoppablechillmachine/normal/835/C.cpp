#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ld> vld;
typedef vector<bool> vb;

#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz size
#define rsz resize
#define fro for
#define itn int
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<int>(cout, " "))

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int SMAXN = 1e3 + 10;
const int P = 259;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-10;
const ld PI = acos(-1);

inline void error()
{
    cout << -1;
    exit(0);
}

ll n, m, k, a, x, y, pref[110][110][11], arr2[110][110][11], cnt[110][110], cnt2[110][110], pref2[110][110], l1, r1, l2, r2;
vector<vvi> arr(110);
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    forn(i, 100)
    {
        arr[i].rsz(110);
    }
    forn(i, n)
    {
        cin >> x >> y >> a;
        //arr[y].rsz(110);
        arr[y][x].pb(a);
        cnt[y][x]++;
    }
    forn(i, 100)
    {
        forn(j, 100)
        {
            fore(j1, k + 1)
            {
                pref[i][j][j1] = pref[i][j - 1][j1];
                fore(j22, arr[i][j].size())
                {
                    pref[i][j][j1] +=(arr[i][j][j22] + j1) % (k + 1);
                }
            }
            pref2[i][j] = pref2[i][j - 1] + cnt[i][j];
        }
    }

    forn(i, 100)
    {
        forn(j, 100)
        {
            forn(j1, i)
            {
                fore(j2, k + 1)
                {
                    arr2[i][j][j2] += pref[j1][j][j2];
                }
                cnt2[i][j] += pref2[j1][j];
            }
        }
    }
    forn(i, m)
    {
        cin >> a >> l1 >> r1 >> l2 >> r2;
        a %= (k + 1);
        ll sum = arr2[r2][l2][a] - arr2[r1 - 1][l2][a] - arr2[r2][l1 - 1][a] + arr2[r1 - 1][l1 - 1][a],
        now = cnt2[r2][l2] - cnt2[r1 - 1][l2] - cnt2[r2][l1 - 1] + cnt2[r1 - 1][l1 - 1];
        cout << sum << endl;
    }
    return 0;
}