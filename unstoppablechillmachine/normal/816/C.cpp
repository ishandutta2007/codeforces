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
#define forn(i, n) for (int i(1); i <= n; i++)
#define fore(i, n) for (int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<int>(cout, " "))

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

int a[SMAXN][SMAXN], c[SMAXN][SMAXN], n, m, cnt, bal[SMAXN][SMAXN], min1 = INF, mini = -1, res;

bool check()
{
    forn(i, n)
    {
        int res = a[i][1] - c[i][1];
        if (res < 0 || c[i][1] < 0) return false;
        for(int j = 2; j <= m; j++)
        {
            if (a[i][j] - c[i][j] != res || a[i][j] < c[i][j] || c[i][j] < 0) return false;
        }
    }
    return true;
}

int f(int a1)
{
    int res = 0;
    forn(i, m) res += c[1][i];
    forn(i, n)
    {
        res += a[i][1] - c[i][1];
    }
    return res;
}

void get(int a1)
{
    cout << f(a1) << endl;
    forn(i, m)
    {
        forn(j, c[1][i]) cout << "col " << i << endl;
    }
    forn(i, n)
    {
        forn(j, a[i][1] - c[i][1]) cout << "row " << i << endl;
    }
    exit(0);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> m;
    forn(i, n)
    forn(j, m)
    {
        cin >> a[i][j];
    }

    forn(j, m - 1)
    {
        res = a[1][j] - a[1][j + 1];
        for(int i = 2; i <= n; i++)
        {
            if (a[i][j] - a[i][j + 1] != res)
            {
                cout << -1;
                exit(0);
            }
        }
    }

    forn(i, n)
    forn(j, m)
    {
        bal[i][j] = a[i][j] - a[i][j - 1];
    }

    fore(i, 510)
    {
        int cnt = 0;
        forn(i1, n)
        forn(j, m)
        {
            c[i1][j] = 0;
        }
        forn(i1, n)
        {
            c[i1][1] = i;
        }

        for(int i1 = 1; i1 <= n; i1++)
        for(int j = 2; j <= m; j++)
        {
            c[i1][j] = c[i1][j - 1] + bal[i1][j];
        }

        if (check())
        {
            //cout << i << " " << f(i) << endl;
            if (f(i) < min1)
            {
                min1 = f(i);
                mini = i;
            }
        }
    }
    //cout << mini << endl;
    forn(i1, n)
    forn(j, m)
    {
        c[i1][j] = 0;
    }
    forn(i1, n)
    {
        c[i1][1] = mini;
    }

    for(int i1 = 1; i1 <= n; i1++)
    for(int j = 2; j <= m; j++)
    {
        c[i1][j] = c[i1][j - 1] + bal[i1][j];
    }

    get(mini);
    return 0;
}