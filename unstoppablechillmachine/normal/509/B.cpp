#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define endl "\n"
#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int P = 239017;
const long long BINF = 1e18 + 10;
const long double EPS = 1e-9;
const long double PI = acos(-1);

#define TASK "printing"

const int N = 110;

int n, k;
pair<int, int> arr[N];
vector<pair<int, int> > ans[N];
_ void source()
{
    cin >> n >> k;
    forn(i, n) {
        cin >> arr[i].f;
        arr[i].sec = i;
    }
    sort(arr + 1, arr + n + 1);
    if (arr[n].f - arr[1].f > k) {
        cout << "NO";
        exit(0);
    }
    cout << "YES" << endl;
    int cur = 1;
    for (int i = 1; i <= k; i++) {
        while (cur <= n && !arr[cur].f) {
            cur++;
        }
        if (cur > n) {
            break;
        }
        int now = arr[cur].f;
        if (cur > 1) {
            now = 0;
        }
        for (int j = cur; j <= n; j++) {
            if (arr[j].f > now) {
                ans[arr[j].sec].pb(mk(now + 1, i));
                arr[j].f -= now + 1;
            }
            else {
                ans[arr[j].sec].pb(mk(now, i));
                arr[j].f -= now;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto it : ans[i]) {
            for (int j = 1; j <= it.f; j++) {
                cout << it.sec << " ";
            }
        }
        cout << endl;
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