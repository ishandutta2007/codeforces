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
#define chcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<int>(cout, " "))

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int SMAXN = 1e3 + 10;
const int P = 2;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-10;
const ld PI = acos(-1);

inline void error()
{
    cout << -1;
    exit(0);
}

int n, a, b;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0));
    scanf("%d", &n);
    forn(i, n)
    {
        scanf("%d%d", &a, &b);
        ll d = ll(a) * ll(b);
        int l = 0, r = 1e6 + 10;
        int cnt = 0;
        while (r - l - 1)
        {
            ll mid = (l + r) / 2;
            if (mid * mid * mid > d) r = mid;
            else l = mid;
            cnt++;
            assert(cnt < 50);
        }
        ll c = ll(l);
        if (c * c * c != ll(a) * ll(b) || a % c || b % c)
        {
            printf("%c%c%c", 'n', 'o', '\n');
            continue;
        }
        printf("%c%c%c%c", 'y', 'e', 's', '\n');
    }
    return 0;
}