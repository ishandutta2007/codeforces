#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const int N = 2e5 + 5;
const LL INF = (1ll << 62) - 1;
const double pi = acos(-1);
mt19937 rng(time(0));

int T, n;
int a[N], b[N], cnt[N], first[N], v[N];
bool flag;
vector<int> g[N];

void dfs(int x) {
    v[x] = 1;
    for (auto u : g[x])
        if (!v[u])
            dfs(u);
        else if (v[u] == 1)
            flag = false;
    v[x] = 2;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) g[i].clear(), cnt[i] = first[i] = v[i] = 0;
        rep(i, 1, n) cin >> a[i], cnt[a[i]]++;
        rep(i, 1, n) cin >> b[i];

        int num = 0;
        rep(i, 1, n) if (cnt[i] > cnt[num]) num = i;

        rep(i, 1, n) if (a[i] != num && b[i] != num) {
            if (!first[b[i]])
                first[b[i]] = i;
            else
                g[i].PB(first[b[i]]);
        }
        rep(i, 1, n) if (a[i] != num && b[i] != num && first[a[i]]) g[first[a[i]]].PB(i);

        flag = true;
        rep(i, 1, n) if (!v[i]) dfs(i);
        cout << (flag ? "AC\n" : "WA\n");
    }
    return 0;
}