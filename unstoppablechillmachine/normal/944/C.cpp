#include <bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast", "no-stack-protector")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "tune=native", "abm")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define rsz resize
#define int ll
#define forn(i, n) for (int i(1); i <= n; i++)
#define fore(i, n) for (int i(0); i < n; i++)

#define next nextt
#define prev prevv
#define left leftt
#define right rightt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-6;

mt19937 Random(int(time(0)));

const int N = 1e5 + 10;
int sum[N];

vector<vector<int> > g;

void dfs(int v, int cur_h = 0) {
    sum[cur_h]++;
    for (auto u : g[v]) {
        dfs(u, cur_h + 1);
    }
}

_ void source() {
    int n;
    cin >> n;
    g.rsz(n + 1);
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        g[a].pb(i);
    }
    dfs(1);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans += (sum[i] & 1);
    }
    cout << ans;
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    source();
    return 0;
}