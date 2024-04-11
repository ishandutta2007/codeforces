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
const int MAXN = 1e7 + 10;
const int LOG = 20;
const long long BINF = 1e18 + 10;
const long long LINF = LLONG_MAX;
const long double EPS = 1e-9;
const long double PI = acos(-1);

_ void error()
{
    cout << -1;
    exit(0);
}

#define TASK ""

int t[MAXN], f[MAXN];

void relax(int v)
{
    t[v] = min(t[2 * v], t[2 * v + 1]);
}

void push(int v)
{
    t[2 * v] += f[v];
    t[2 * v + 1] += f[v];
    f[2 * v] += f[v];
    f[2 * v + 1] += f[v];
    f[v] = 0;
}

void upd(int v, int l, int r, int a, int b)
{
    if (l > b || r < a)
    {
        return;
    }
    push(v);
    if (l >= a && r <= b)
    {
        t[v]++;
        f[v]++;
    }
    else
    {
        int mid = (l + r) / 2;
        upd(2 * v, l, mid, a, b);
        upd(2 * v + 1, mid + 1, r, a, b);
        relax(v);
    }
}

int getmin(int v, int l, int r, int a, int b)
{
    if (l > b || r < a)
    {
        return INF;
    }
    push(v);
    if (l >= a && r <= b)
    {
        return t[v];
    }
    else
    {
        int mid = (l + r) / 2;
        return min(getmin(2 * v, l, mid, a, b), getmin(2 * v + 1, mid + 1, r, a, b));
    }
}

int n, l, r, cnt;
set<int> st;
unordered_map<int, int> mp;
vector<pii> arr;
_ void source()
{
    cin >> n;
    forn(i, n)
    {
        cin >> l >> r;
        st.ins(l);
        st.ins(r);
        arr.pb(mk(l, r));
    }
    int prev = *st.begin() - 1;
    for (auto it : st)
    {
        cnt += min(it - prev, ll(2));
        mp[it] = cnt;
        prev = it;
        //cout << it << " " << cnt << endl;
    }
    fore(i, n)
    {
        arr[i].f = mp[arr[i].f];
        arr[i].sec = mp[arr[i].sec];
        upd(1, 1, 1.5e6, arr[i].f, arr[i].sec);
    }
    fore(i, n)
    {
        //cout << arr[i].f << " " << arr[i].sec << endl;
        //cout << getmin(1, 1, 1.5e6, arr[i].sec, arr[i].sec) << endl;
        if (getmin(1, 1, 1.5e6, arr[i].f, arr[i].sec) > 1)
        {
            cout << i + 1;
            exit(0);
        }
    }
    cout << -1;
}

signed main()
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