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
#define chcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<int>(cout, " "))

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int SMAXN = 1e3 + 10;
const int P = 259;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-6;
const ld PI = acos(-1);

ll arr[4 * MAXN], k;

void relax(int a)
{
    arr[a] = (arr[2 * a] * arr[2 * a + 1]) % k;
}

void upd(int a)
{
    while (a)
    {
        a /= 2;
        relax(a);
    }
}

ll getmult(int l, int r)
{
    ll res = 1;
    while (l <= r)
    {
        if (l % 2 == 1)
        {
            res = (res * arr[l]) % k;
            l++;
        }
        if (r % 2 == 0)
        {
            res = (res * arr[r]) % k;
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return res;
}

ll n, m, a[MAXN], l, r, ans = 0;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> k;
    forn(i, n)
    {
        cin >> a[i];
    }
    int s = 1 << (32 - __builtin_clz(n));
    forn(i, n)
    {
        arr[s + i - 1] = a[i];
        upd(s + i - 1);
    }
    for (int i = 1; i <= n; i++)
    {
        l = i;
        r = n + 1;
        while (r - l - 1)
        {
            int mid = (l + r) / 2;
            if (getmult(s + i - 1, s + mid - 1) % k == 0)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        if (getmult(s + i - 1, s + l - 1) % k == 0) ans += n - l + 1;
        else ans += n - r + 1;
    }
    cout << ans;
    return 0;
}