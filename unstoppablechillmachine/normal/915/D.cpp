#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize ("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")

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
//#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

vector<int> used;
bool t, was;
int n, arr[510][510], from[510];
vector<int> arr2;
vector<vector<int> > g;
void dfs(int v) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (arr[v][u]) {
            if (!used[u]) {
                dfs(u);
            }
            else if (used[u] == 1) {
                t = false;
                return;
            }
        }
    }
    used[v] = 2;
}

void dfs1(int v, int prev) {
    used[v] = 1;
    from[v] = prev;
    for (int i = 1; i <= n; i++) {
        if (arr[v][i]) {
            if (!used[i]) {
                dfs1(i, v);
            }
            else if (used[i] == 1 && !was) {
                was = true;
                from[i] = v;
                arr2.pb(v);
                int now = from[v];
                while (now != i && now) {
                    assert(now);
                    arr2.pb(now);
                    now = from[now];
                }
                arr2.pb(i);
            }
        }
    }
    used[v] = 2;
}

_ void source() {
    int m;
    cin >> n >> m;
    g.rsz(n + 1);
    used.rsz(n + 1);
    vector<pair<int, int> > ed;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
        g[a].pb(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs1(i, 0);
        }
    }
    if (!was) {
        cout << "YES";
        exit(0);
    }
    for (int i = 0; i < arr2.size(); i++) {
        int a = i - 1;
        if (a < 0) {
            a += int(arr2.size());
        }
        ed.pb(mk(arr2[i], arr2[a]));
    }
    for (auto it : ed) {
        arr[it.f][it.sec] = false;
        t = true;
        fill(all(used), 0);
        for (int j = 1; j <= n; j++) {
            if (!used[j]) {
                dfs(j);
            }
        }
        if (t) {
            cout << "YES";
            exit(0);
        }
        arr[it.f][it.sec] = true;
    }
    cout << "NO";
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
    source();
    return 0;
}