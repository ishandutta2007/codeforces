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
const ld EPS = 1e-9;
const ld PI = acos(-1);

int n, m, r1, r2, ans, arr[10];

inline int f(int a)
{
    if (!a) return 1;
    int res = 0;
    while(a)
    {
        res++;
        a /= 7;
    }
    return res;
}

inline bool check()
{
    bool used[10];
    fore(i, 7) used[i] = false;
    forn(i, r1 + r2)
    {
        if (!used[arr[i]]) used[arr[i]] = true;
        else return false;
    }
    return true;
}

inline bool check2()
{
    int j = 0;
    while (arr[j] == 0 && j <= r1) j++;
    if (j <= r1)
    {
        int sum = 0;
        for(int i = j; i <= r1; i++)
        {
            sum = sum * 7 + arr[i];
        }
        if (sum >= n) return false;
    }
    j = r1 + 1;
    while (j <= r1 + r2 && arr[j] == 0) j++;
    if (j <= r1 + r2)
    {
        int sum = 0;
        for(itn i = j; i <= r1 + r2; i++)
        {
            sum = sum * 7 + arr[i];
        }
        if (sum >= m) return false;
    }
    return true;
}

inline void gen(int a)
{
    if (a > r1 + r2)
    {
        if (!check()) return;
        if (check2()) ans++;
        return;
    }
    else fore(i, 7)
    {
        arr[a] = i;
        gen(a + 1);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> m;
    r1 = f(n - 1);
    r2 = f(m - 1);
    //cout << r1 << " " << r2 << endl;
    if (r1 + r2 > 7)
    {
        cout << 0;
        exit(0);
    }
    gen(1);
    cout << ans;
    return 0;
}