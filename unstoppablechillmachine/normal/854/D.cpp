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
#define endl "\n"
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


struct st
{
    ll from, to, time, cost;
};

bool cmp(st a, st b)
{
    return a.time > b.time;
}

ll n, m, k, cur, cur2, dist[MAXN], dist2[MAXN], ans = BINF;
vector<st> arr;
pll suf[MAXN];

_ void source()
{
    cin >> n >> m >> k;
    arr.rsz(m);
    fore(i, m)
    {
        cin >> arr[i].time >> arr[i].from >> arr[i].to >> arr[i].cost;
    }
    forn(i, n)
    {
        dist[i] = INF;
        dist2[i] = INF;
    }
    int cnt = n, cnt2 = n;
    cur = INF * n;
    cur2 = INF * n;
    sort(all(arr), cmp);
    for (int i = 0; i < int(arr.size()); i++)
    {
        if (arr[i].from == 0)
        {
            //cout << i << endl;
            if (dist[arr[i].to] > arr[i].cost)
            {
                cur = cur - dist[arr[i].to] + arr[i].cost;
                if (dist[arr[i].to] == INF)
                {
                    cnt--;
                }
                dist[arr[i].to] = arr[i].cost;
            }
        }
        suf[arr[i].time] = mk(cur, cnt);
    }
    suf[int(1e6 + 1)] = mk(BINF, n);
    for (int i = 1e6; i > 0; i--)
    {
        if (suf[i].f == 0)
        {
            suf[i] = suf[i + 1];
        }
    }
    reverse(all(arr));
    for (int i = 0; i < int(arr.size()); i++)
    {
        if (arr[i].to == 0)
        {
            if (dist2[arr[i].from] > arr[i].cost)
            {
                cur2 = cur2 - dist2[arr[i].from] + arr[i].cost;
                if (dist2[arr[i].from] == INF)
                {
                    cnt2--;
                }
                dist2[arr[i].from] = arr[i].cost;
            }
        }
        //cout << arr[i].time << " " << cnt2 << " " << suf[min(ll(1e6 + 1), arr[i].time + k + 1)].sec << endl;
        if (!cnt2 && !suf[min(ll(1e6 + 1), arr[i].time + k + 1)].sec)
        {
            ans = min(ans, cur2 + suf[min(ll(1e6 + 1), arr[i].time + k + 1)].f);
        }
    }
    if (ans >= BINF)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
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