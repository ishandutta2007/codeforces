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

string s;
int n, ans[MAXN], k;
vector<vector<bitset<15> > > dp;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    n = s.size();
    dp.rsz(n + 1);
    forn(i, n)
    {
        dp[i].rsz(n + 1);
    }
    s.ins(s.begin(), ' ');
    forn(i, n)
    {
        dp[i][i].set(1);
        ans[1]++;
        if (i < n)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1].set(1);
                ans[1]++;
            }
        }
    }

    for (int len = 3; len <= n; len++)
    {
        for (int l = 1; l <= n - len + 1; l++)
        {
            int r = l + len - 1;
            if (s[l] == s[r] && dp[l + 1][r - 1].test(1))
            {
                dp[l][r].set(1);
                ans[1]++;
                //cout << l << " " << r << endl;
            }
        }
    }

    int k = int(log2(n)) + 1;
    for (int i = 2; i <= k; i++)
    {
        for (int l = 1; l <= n; l++)
        {
            for (int r = l + 1; r <= n; r++)
            {
                if (!dp[l][r].test(1)) continue;
                int len = r - l + 1, r2 = l + len / 2 - 1, l2 = r - len / 2 + 1;
                if (dp[l][r2].test(i - 1) && dp[l2][r].test(i - 1))
                {
                    dp[l][r].set(i);
                    ans[i]++;
                }
            }
        }
    }
    forn(i, n)
    {
        cout << ans[i] << " ";
    }

    return 0;
}