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
const int MAXN = 2e5 + 10;
const int LOG = 30;
const int P = 239017;
const long long BINF = 1e18 + 10;
const long long LINF = LLONG_MAX;
const long double EPS = 1e-6;
const long double PI = acos(-1);

#define TASK ""

int n, arr[MAXN], l_lim[MAXN], r_lim[MAXN], near_l[MAXN][LOG + 1], near_r[MAXN][LOG + 1], ans;

_ void source()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    l_lim[1] = 0;
    stack<int> st;
    st.push(1);
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] <= arr[i - 1])
        {
            l_lim[i] = i - 1;
            st.push(i);
        }
        else
        {
            while (!st.empty() && arr[st.top()] < arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                l_lim[i] = 0;
            }
            else
            {
                l_lim[i] = st.top();
            }
            st.push(i);
        }
    }
    while (!st.empty()) st.pop();
    r_lim[n] = n + 1;
    st.push(n);
    for (int i = n - 1; i >= 1; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            r_lim[i] = i + 1;
            st.push(i);
        }
        else
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                r_lim[i] = n + 1;
            }
            else
            {
                r_lim[i] = st.top();
            }
            st.push(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= LOG; j++)
        {
            if ((arr[i - 1] >> j) & 1)
            {
                near_l[i][j] = i - 1;
            }
            else
            {
                near_l[i][j] = near_l[i - 1][j];
            }
        }
    }
    for (int j = 0; j <= LOG; j++)
    {
        near_r[n + 1][j] = n + 1;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= LOG; j++)
        {
            if ((arr[i + 1] >> j) & 1)
            {
                near_r[i][j] = i + 1;
            }
            else
            {
                near_r[i][j] = near_r[i + 1][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int l = l_lim[i], r = r_lim[i];
        //cout << l_lim[i] << " " << r_lim[i] << " ";
        for (int j = 0; j <= LOG; j++)
        {
            if ((arr[i] >> j) & 1)
            {
                continue;
            }
            l = max(l, near_l[i][j]);
            r = min(r, near_r[i][j]);
        }
        //cout << l << " " << r << " ";
        ans += (l - l_lim[i]) * (r_lim[i] - i) + (r_lim[i] - r) * (i - l);
    }
    cout << ans;
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