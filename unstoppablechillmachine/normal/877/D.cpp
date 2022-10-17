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
//#define int ll
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
const int MAXN = 2e5 + 10;
const int LOG = 30;
const int P = 239017;
const long long BINF = 1e18 + 10;
const long long LINF = LLONG_MAX;
const long double EPS = 1e-6;
const long double PI = acos(-1);

#define TASK ""
int n, m, k, d[1010][1010];
char ch;
bool t[1010][1010], used[1010][1010];
pair<int, int> p, p2;
queue<pair<pair<int, int>, int> > q;

_ void go(pair<int, int> v, int delta_x, int delta_y, int new_dist)
{
    for (int i = 1; i <= k; i++)
    {
        v.f += delta_x;
        v.sec += delta_y;
        if (v.f > n || v.sec > m || v.f < 1 || v.sec < 1 || !t[v.f][v.sec])
        {
            break;
        }
        if (!used[v.f][v.sec])
        {
            used[v.f][v.sec] = true;
            d[v.f][v.sec] = new_dist;
            q.push(mk(v, new_dist));
        }
        else if (d[v.f][v.sec] < new_dist)
        {
            break;
        }
    }
}
_ void source()
{
    cin >> n >> m >> k;
    forn(i, n)
    {
        forn(j, m)
        {
            cin >> ch;
            if (ch == '.')
            {
                t[i][j] = 1;
            }
        }
    }
    cin >> p.f >> p.sec >> p2.f >> p2.sec;
    used[p.f][p.sec] = true;
    d[p.f][p.sec] = 0;
    q.push(mk(p, 0));
    while (!q.empty())
    {
        pair<int, int> v = q.front().f;
        int dist = q.front().sec;
        q.pop();
        if (v == p2)
        {
            cout << dist;
            exit(0);
        }
        go(v, 1, 0, dist + 1);
        go(v, -1, 0, dist + 1);
        go(v, 0, 1, dist + 1);
        go(v, 0, -1, dist + 1);
    }
    cout << -1;
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