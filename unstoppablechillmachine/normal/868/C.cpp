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

int cnt[MAXN], k;
vector<int> arr;
_ bool check(int len)
{
    vector<int> used(10, 0);
    map<int, int> mp;
    fore(i, arr.size())
    {
        mp[arr[i]]++;
        if (mp[arr[i]] > cnt[arr[i]])
        {
            return false;
        }
    }
    fore(i, arr.size())
    {
        fore(j, k)
        {
            if ((arr[i] >> j) & 1)
            {
                used[j]++;
            }
        }
    }
    fore(i, k)
    {
        if (used[i] > len / 2)
        {
            return false;
        }
    }
    return true;
}

_ void rec(int now, int len)
{
    if (now == len)
    {
        if (check(len))
        {
            cout << "YES";
            exit(0);
        }
        return;
    }
    for (int i = 0; i < (1 << k); i++)
    {
        arr.pb(i);
        rec(now + 1, len);
        arr.pop_back();
    }
}

int n, a;
_ void source()
{
    cin >> n >> k;
    forn(i, n)
    {
        int cur = 0;
        fore(j, k)
        {
           cin >> a;
           if (a == 1)
           {
               cur += (1 << j);
           }
        }
        cnt[cur]++;
    }
    for (int len = 1; len <= k; len++)
    {
        rec(0, len);
    }
    cout << "NO";
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