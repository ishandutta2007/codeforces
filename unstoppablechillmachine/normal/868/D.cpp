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
//#define endl "\n"
#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int LOG = 20;
const int P = 239017;
const long long BINF = 1e18 + 10;
const long long LINF = LLONG_MAX;
const long double EPS = 1e-2;
const long double PI = acos(-1);

_ void error()
{
    cout << -1;
    exit(0);
}

#define TASK "printing"

int root = 1, cnt[210], kol[210][210];
map<char, int> mp[210][210];
string s;
int n, m, l, r, ans[210];
string st[210], suf[210], pref[210];
void add(string s, int num)
{
    int v = root;
    fore(i, min(6, int(s.size())))
    {
        char ch = s[i];
        if (!mp[num][v][ch])
        {
            cnt[num]++;
            mp[num][v][ch] = cnt[num];
        }
        v = mp[num][v][ch];
        kol[num][v]++;
    }
}

void get(string s, int num)
{
    while (!s.empty())
    {
        add(s, num);
        s.ers(s.begin());
    }
}

void dfs(int v, int from, int to)
{
    assert(v > 0 && v <= cnt[from]);
    add(s, to);
    for (auto it : mp[from][v])
    {
        if (it.sec > 0 && it.sec <= cnt[from])
        {
            s += it.f;
            dfs(it.sec, from, to);
            s.ers(--s.end());
        }
    }
}

void merge_tries(int ff, int ss, int to)
{
    s = "";
    dfs(root, ff, to);
    s = "";
    dfs(root, ss, to);
}

bool go(string s, int num)
{
    int v = root;
    fore(i, s.size())
    {
        char ch = s[i];
        v = mp[num][v][ch];
        if (!kol[num][v])
        {
            mp[num][v].ers(ch);
            return false;
        }
    }
    return true;
}

void check_mid(int l, int r, int to)
{
    string ss;
    int n = st[l].size(), n2 = st[r].size();
    for (int len_f = 1; len_f <= min(5, n); len_f++)
    {
        ss.clear();
        for (int i = n - 1 - len_f + 1; i < n; i++)
        {
            ss += st[l][i];
        }
        for (int i = 0; i < min(6 - len_f, n2); i++)
        {
            ss += st[r][i];
        }
        get(ss, to);
    }
}

int check_upd(int mn, int num)
{
    for (int i = 6; i > mn; i--)
    {
        bool t = true;
        int lim = 1 << i;
        for (int j = 0; j < lim; j++)
        {
            string s2;
            for (int j2 = 0; j2 < i; j2++)
            {
                if ((j >> j2) & 1)
                {
                    s2 += "1";
                }
                else
                {
                    s2 += "0";
                }
            }
            if (!go(s2, num))
            {
                t = false;
                break;
            }
        }
        if (t)
        {
            return i;
        }
    }
    return mn;
}

void source()
{
    cin >> n;
    forn(i, n)
    {
        cnt[i] = 1;
        cin >> st[i];
        pref[i] = suf[i] = st[i];
        get(st[i], i);
        ans[i] = check_upd(0, i);
    }
    cin >> m;
    forn(i, m)
    {
        cnt[n + i] = 1;
        cin >> l >> r;
        if (st[l].size() + st[r].size() < 100)
        {
            st[n + i] = st[l] + st[r];
        }
        else
        {
            st[n + i] = suf[l] + pref[r];
        }
        if (st[n + i].size() < 100)
        {
            pref[n + i] = st[n + i];
            suf[n + i] = st[n + i];
        }
        else
        {
            if (st[r].size() > 100) suf[n + i] = suf[r];
            else suf[n + i] = suf[l] + st[r];
            if (st[l].size() > 12)
            pref[n + i] = pref[l];
            else pref[n + i] = st[l] + pref[r];
        }
        merge_tries(l, r, n + i);
        check_mid(l, r, n + i);
        ans[n + i] = check_upd(max(ans[l], ans[r]), n + i);
        cout << ans[n + i] << endl;
    }
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