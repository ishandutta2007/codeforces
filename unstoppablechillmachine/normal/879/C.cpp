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

#define TASK ""

int a, a1, a2, a3, n;
char ch;
bool t;
vector<pair<char, int> > ans;

_ bool f(int a, int b)
{
    return ((a >> b) & 1);
}
_ void source()
{
    int now1 = 0, now2 = 1023;
    cin >> n;
    forn(i, n)
    {
        cin >> ch >> a;
        if (ch == '|')
        {
            now1 |= a;
            now2 |= a;
        }
        if (ch == '^')
        {
            now1 ^= a;
            now2 ^= a;
        }
        if (ch == '&')
        {
            now1 &= a;
            now2 &= a;
        }
    }
    int need_and = 1023, need_xor = 0, need_or = 0;
    for (int i = 0; i <= 9; i++)
    {
        if (f(now1, i) && f(now2, i))
        {
            need_or |= (1 << i);
        }
        else if (!f(now1, i) && f(now2, i))
        {
            continue;
        }
        else if (!f(now1, i) && !f(now2, i))
        {
            need_and ^= (1 << i);
        }
        else
        {
            need_xor |= (1 << i);
        }
    }
    cout << 3 << endl << "& " << need_and << endl << "^ " << need_xor << endl << "| " << need_or;
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