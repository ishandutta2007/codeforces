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

#define _ inline
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
#define pw(x) (1 << (x))
#define sqr(x) ((x) * (x))
#define fro for
#define itn int
#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<int>(cout, " "))
#define endl "\n"
#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int LOG = 30;
const int P = 239017;
const long long BINF = 1e18 + 10;
const long long LINF = LLONG_MAX;
const long double EPS = 1e-6;
const long double PI = acos(-1);

#define TASK "seq"

int n, a;
bool t;
vector<int> arr1, arr2, arr3;
_ void source()
{
    cin >> n;
    forn(i, n)
    {
        cin >> a;
        if (a == 0)
        {
            arr3.pb(a);
        }
        if (a > 0)
        {
            arr2.pb(a);
        }
        if (a < 0)
        {
            if (t)
            {
                arr3.pb(a);
            }
            else
            {
                arr1.pb(a);
                t = true;
            }
        }
    }
    if (arr2.empty())
    {
        sort(all(arr3));
        arr2.pb(arr3[0]);
        arr2.pb(arr3[1]);
        arr3.ers(arr3.begin());
        arr3.ers(arr3.begin());
    }
    cout << arr1.size() << " ";for (auto it : arr1) cout << it << " ";
    cout << endl;
    cout << arr2.size() << " ";for (auto it : arr2) cout << it << " ";
    cout << endl;
    cout << arr3.size() << " ";for (auto it : arr3) cout << it << " ";
}

signed main()
{
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    source();
    return 0;
}