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
//#define endl "\n"
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

int n, ans;
int arr[MAXN];
unordered_set<int> st;
map<vi, int> mp;
void fact(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        int cnt = 0;
        while (n % i == 0)
        {
            n /= i;
            cnt++;
        }
        if (cnt)
        {
            st.ins(i);
        }
    }
    if (n > 1)
    {
        st.ins(n);
    }
}

int f(int a, int b)
{
    int res = 0;
    while (a && a % b == 0)
    {
        a /= b;
        res++;
    }
    return res;
}

_ void dfs(vi Vec)
{
    vi arr;
    set<int> st2;
    if (mp.find(Vec) != mp.end())
    {
        return;
    }
    if (Vec.size() == 1)
    {
        mp[Vec] = Vec[0];
        return;
    }
    int mx = -1, prev = -1;
    fore(i, Vec.size())
    {
        mx = max(mx, Vec[i]);
    }
    for (int i = mx; i > 0; i--)
    {
        vi Vec1;
        st2.clear();
        for (int j = 0; j < Vec.size(); j++)
        {
            if (Vec[j] >= i)
            {
                st2.ins(Vec[j] - i);
            }
            else
            {
                st2.ins(Vec[j]);
            }
        }
        for (auto it : st2)
        {
            Vec1.pb(it);
        }
        dfs(Vec1);
        arr.pb(mp[Vec1]);
    }
    sort(all(arr));
    for (auto it : arr)
    {
        if (it - prev > 1)
        {
            mp[Vec] = prev + 1;
            return;
        }
        prev = it;
    }
    mp[Vec] = prev + 1;
    return;
}

_ void source()
{
    cin >> n;
    forn(i, n)
    {
        cin >> arr[i];
        fact(arr[i]);
    }
    for (auto it : st)
    {
        vi Vec;
        set<int> st2;
        int sum = 0;
        forn(i, n)
        {
            st2.ins(f(arr[i], it));
        }
        for (auto u : st2)
        {
            Vec.pb(u);
        }
        dfs(Vec);
        ans ^= mp[Vec];
    }
    if (!ans)
    {
        cout << "Arpa";
    }
    else
    {
        cout << "Mojtaba";
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