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

int n, m, k, from, dist, v, to, to2;
pii arr[10010];
//vector<vpii> Vec(10010);
bool used[10010], used0[10010];
queue<pii> q0, q1;
vector<bitset<10010> > bt1(10010), bt2(10010);
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> m >> k;
    forn(i, k)
    {
        cin >> arr[i].f >> arr[i].sec;
        if (arr[i].f == 1 && arr[i].sec == 1)
        {
            from = i;
        }
        if (arr[i].f == n && arr[i].sec == m)
        {
            to2 = i;
        }
    }
    arr[k + 1] = mk(n, m);
    to = k + 1;
    forn(i, k)
    forn(j, k)
    {
        if (i == j) continue;
        if ((arr[i].f == arr[j].f && abs(arr[i].sec - arr[j].sec) == 1) || (arr[i].sec == arr[j].sec && abs(arr[i].f - arr[j].f) == 1))
        {
            //Vec[i].pb(mk(j, 0));
            bt1[i].set(j);
        }
        else if (abs(arr[i].f - arr[j].f) <= 2 || abs(arr[i].sec - arr[j].sec) <= 2)
        {
            //Vec[i].pb(mk(j, 1));
            bt1[i].set(j);
            bt2[i].set(j);
        }
    }
    forn(i, k)
    {
        if (n - arr[i].f <= 1 || m - arr[i].sec <= 1)
        {
            bt1[i].set(k + 1);
            bt2[i].set(k + 1);
        }
        //Vec[i].pb(mk(k + 1, 1));
    }
    //arr.clear();
    q0.push(mk(from, 0));
    used[1] = true;
    used0[1] = true;
    while(!q0.empty() || !q1.empty())
    {
        if (!q0.empty())
        {
            v = q0.front().f;
            dist = q0.front().sec;
            q0.pop();
        }
        else
        {

            v = q1.front().f;
            dist = q1.front().sec;
            q1.pop();
        }
        //cout << v << " " << dist << endl;
        if (v == to || v == to2)
        {
            cout << dist;
            exit(0);
        }
        forn(i, k + 1)
        {
            if (bt1[v].test(i) && !bt2[v].test(i) && !used0[i])
            {
                used0[i] = true;
                q0.push(mk(i, dist));
            }
            else if (bt1[v].test(i) && !used[i])
            {
                used[i] = true;
                q1.push(mk(i, dist + 1));
            }
        }
    }
    cout << -1;
    return 0;
}