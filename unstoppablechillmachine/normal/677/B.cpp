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
const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int SMAXN = 1e3 + 10;
const int P = 259;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-10;
const ld PI = acos(-1);

ll sum, ans, n, h, k, a[MAXN], cnt;
vll Vec;
bool used[MAXN];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    ll b;
    cin >> n >> h >> k;
    forn(i, n)
    {
        cin >> a[i];
        if (cnt + a[i] <= h)
        {
            cnt += a[i];
            continue;
        }
        if ((cnt - (h - a[i])) % k == 0)
        {
            b = (cnt - (h - a[i])) / k;
        }
        else
        {
            b = (cnt - (h - a[i])) / k + 1;
        }
        ans += b;
        cnt = cnt - min(cnt, k * b) + a[i];
    }
    if (cnt % k == 0) ans += cnt / k;
    else ans += cnt / k + 1;
    cout << ans;
    return 0;
}