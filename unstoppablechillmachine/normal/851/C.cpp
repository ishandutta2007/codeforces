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

struct st
{
    ld a, b, c, d, e;
};

int n;
st k;
vector<st> arr, arr2;
vi ans;
_ ld mult(st a, st b)
{
    return a.a * b.a + a.b * b.b + a.c * b.c + a.d * b.d + a.e * b.e;
}

_ ld angle2(st a, st b)
{
    return acos(mult(a, b) / mult(a, a) / mult(b, b));
}

_ bool cmp(st a, st b)
{
    return acos(mult(a, k) / mult(a, a) / mult(k, k)) < acos(mult(b, k) / mult(b, b) / mult(k, k));
}

_ void source()
{
    ld p = asin(1);
    k.a = -1e3, k.b = -1e3, k.c = -1e3, k.d = -1e3, k.e = -1e3;
    cin >> n;
    arr.rsz(n);
    fore(i, n)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d >> arr[i].e;
    }
    fore(i, n)
    {
        bool t = true;
        arr2.clear();
        fore(j, n)
        {
            if (j != i)
            {
                st f;
                f.a = arr[j].a - arr[i].a;
                f.b = arr[j].b - arr[i].b;
                f.c = arr[j].c - arr[i].c;
                f.d = arr[j].d - arr[i].d;
                f.e = arr[j].e - arr[i].e;
                arr2.pb(f);
            }
        }
        int lim = arr2.size();
        fore(j, lim)
        {
            fore(j2, lim)
            {
                if (j == j2)
                {
                    continue;
                }
                {
                    if (angle2(arr2[j], arr2[j2]) < p)
                    {
                        t = false;
                        break;
                    }
                }
            }
            if (!t)
            {
                break;
            }
        }
        if (t)
        {
            ans.pb(i + 1);
        }
    }
    cout << ans.size() << endl;
    fore(i, ans.size())
    {
        cout << ans[i] << " ";
    }
}

int main()
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