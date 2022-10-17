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
string s;
int pref[5010];
_ int get(int l, int r, char need)
{
    if (l > r)
    {
        return 0;
    }
    if (need == 'a')
    {
        return pref[r] - pref[l - 1];
    }
    else
    {
        int len = r - l + 1;
        return len - (pref[r] - pref[l - 1]);
    }
}
_ void source()
{
    int ans = 0;
    cin >> s;
    int n = s.size();
    s.ins(s.begin(), ' ');
    forn(i, n)
    {
        pref[i] = pref[i - 1];
        if (s[i] == 'a')
        {
            pref[i]++;
        }
    }
    for (int l = 1; l <= n; l++)
    {
        for (int r = l - 1; r <= n; r++)
        {
            ans = max(ans, get(1, l - 1, 'a') + get(l, r, 'b') + get(r + 1, n, 'a'));
        }
    }
    cout << ans;
}

signed main()
{
#ifdef EXTRATERRESTRIAL_
    //freopen("input.txt", "r", stdin);
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