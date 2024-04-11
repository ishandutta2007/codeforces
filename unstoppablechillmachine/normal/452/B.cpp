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
const int LOG = 20;
const long long BINF = 1e18 + 10;
const long long LINF = 1e18 + 10;
const long double EPS = 1e-10;
const long double PI = acos(-1);

_ void error()
{
    cout << -1;
    exit(0);
}

#define TASK ""

ld dist(pii a, pii b)
{
    return sqrt((a.f - b.f) * (a.f - b.f) + (a.sec - b.sec) * (a.sec - b.sec));
}

int n, m;
set<pii> st;
ld ans = -INF;
pii arr[4];
vpii arr2;
vi res;
_ void source()
{
    cin >> n >> m;
    arr[0] = mk(0, 0);
    arr[1] = mk(n, 0);
    arr[2] = mk(0, m);
    arr[3] = mk(n, m);
    fore(i, 4)
    {
        pii p = arr[i];
        for (int j = -1; j <= 1; j++)
        {
            for (int j2 = -1; j2 <= 1; j2++)
            {
                if (p.f + j >= 0 && p.f + j <= n && p.sec + j2 >= 0 && p.sec + j2 <= m)
                {
                    arr2.pb(mk(p.f + j, p.sec + j2));
                }
            }
        }
    }
    fore(i, arr2.size())
    {
        fore(i2, arr2.size())
        {
            fore(i3, arr2.size())
            {
                fore(i4, arr2.size())
                {
                    st.clear();
                    st.ins(arr2[i]);
                    st.ins(arr2[i2]);
                    st.ins(arr2[i3]);
                    st.ins(arr2[i4]);
                    if (st.size() < 4)
                    {
                        continue;
                    }
                    if (ans < dist(arr2[i], arr2[i2]) + dist(arr2[i2], arr2[i3]) + dist(arr2[i3], arr2[i4]))
                    {
                        ans = dist(arr2[i], arr2[i2]) + dist(arr2[i2], arr2[i3]) + dist(arr2[i3], arr2[i4]);
                        res.clear();
                        res.pb(i);
                        res.pb(i2);
                        res.pb(i3);
                        res.pb(i4);
                    }
                }
            }
        }
    }
    fore(i, res.size())
    {
        cout << arr2[res[i]].f << " " << arr2[res[i]].sec << endl;
    }
}

int main()
{
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    source();
    return 0;
}