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

const int lim = 2100;

struct st
{
    int t, to, p, num;
};

bool cmp(st a, st b)
{
    return a.to < b.to || (a.to == b.to && a.t < b.t);
}

int n, dp[110][lim + 10];
vector<st> arr;
pair<int, int> from[110][lim + 10];
_ void source()
{
    cin >> n;
    arr.rsz(n);
    fore(i, n)
    {
        cin >> arr[i].t >> arr[i].to >> arr[i].p;
        arr[i].num = i + 1;
    }
    sort(all(arr), cmp);
    arr.ins(arr.begin(), {0, 0, 0, 0});
    for (int cur = 0; cur < n; cur++)
    {
        for (int time = 0; time <= lim; time++)
        {
            if (arr[cur + 1].t + time < arr[cur + 1].to)
            {
                if (dp[cur][time] + arr[cur + 1].p > dp[cur + 1][arr[cur + 1].t + time])
                {
                    dp[cur + 1][arr[cur + 1].t + time] = dp[cur][time] + arr[cur + 1].p;
                    from[cur + 1][arr[cur + 1].t + time] = mk(cur, time);
                }
            }
            if (dp[cur][time] > dp[cur + 1][time])
            {
                dp[cur + 1][time] = dp[cur][time];
                from[cur + 1][time] = mk(cur, time);
            }
        }
    }
    pair<int, int> now = mk(n, 0);
    int ans = -1;
    vector<int> res;
    for (int i = 0; i <= lim; i++)
    {
        if (dp[n][i] > ans)
        {
            ans = dp[n][i];
            now.sec = i;
        }
    }
    cout << ans << endl;
    while (now.f)
    {
        pair<int, int> now2 = from[now.f][now.sec];
        if (now2.sec != now.sec)
        {
            res.pb(arr[now.f].num);
        }
        now = now2;
    }
    //sort(all(res));
    reverse(all(res));
    cout << res.size() << endl;
    for (auto it : res)
    {
        cout << it << " ";
    }
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