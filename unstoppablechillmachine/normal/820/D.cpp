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
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<int>(cout, " "))

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int SMAXN = 1e3 + 10;
const int P = 259;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-6;
const ld PI = acos(-1);

inline void error()
{
    cout << -1;
    exit(0);
}

ll n, a[MAXN], num1, num2, bal[MAXN], cnt[MAXN], res, ans, last, mini;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    forn(i, n)
    {
        cin >> a[i];
        if (a[i] <= i) cnt[1]++;
        num1 = (n - i + 1) % n + 1;
        if (num1 > n) num1 %= n;
        num2 = (num1 + a[i]) - 1;
        if (num2 > n) num2 %= n;
        bal[num1 - 1]--;
        bal[num2]++;
    }

    forn(i, n)
    {
        if (i == 1) continue;
        cnt[i] = cnt[i - 1] + bal[i];
    }

    forn(i, n) res += abs(a[i] - i);
    ans = res;
    mini = 1;
    for(int i = 2; i <= n; i++)
    {
        last = a[n - i + 2];
        res += (2 * cnt[i - 1] - n);
        res = res - (n + 1 - last) + (last - 1);
        if (ans > res)
        {
            ans = res;
            mini = i;
        }
    }
    cout << ans << " " << mini - 1 << endl;
    return 0;
}