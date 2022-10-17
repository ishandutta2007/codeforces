#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

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

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random((int)time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const long long BINF = 1e18 + 10;

bool used[1010];
vector<vector<int> > g;
void dfs(int v) {
    used[v] = true;
    for (auto u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

_ void source() {
    int n, x, mx = 0;
    cin >> n >> x;
    g.rsz(n + 1);
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        mx = max(mx, r[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (r[i] >= l[j]) {
                g[i].pb(j);
            }
        }
    }
    if (l[1] != 0 || mx != x) {
        cout << "NO";
        exit(0);
    }
    dfs(1);
    if (used[n]) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}

signed main() {
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