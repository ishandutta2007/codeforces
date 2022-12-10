#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x) cerr << #x << " = " << x << endl
#define dbga(arr, len) {cerr << #arr << " = "; for (int _ = 0; _ < len; _++)\
cerr << arr[_] << " "; cerr << endl;}
#define dbgi(it) {cerr << #it << " = "; for (const auto& _ : it)\
cerr << _ << " "; cerr << endl;}
#else
#define dbg(...) (void)0
#define dbgv(x) (void)0
#define dbga(arr, len) (void)0
#define dbgi(it) (void)0
#endif

using ll = long long;
using dbl = long double;
using pii = pair<int, int>;

const int N = 1e5 + 10;
int a[N];
int b[N];
int minId[N];
vector<int> toUse;

void solve() {
    int n, k;
    memset(minId, -1, sizeof minId);
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < n; ++i) {
        if (minId[a[i]] == -1 || b[minId[a[i]]] < b[i]) {
            if (minId[a[i]] != -1)
                toUse.push_back(b[minId[a[i]]]);
            minId[a[i]] = i;
        } else {
            toUse.push_back(b[i]);
        }
    }
    sort(toUse.begin(), toUse.end());
    ll ans = 0;
    int ptr = 0;
    dbgi(toUse);
    dbga(minId, k);
    for(int i = 0; i < k; ++i) {
        if (minId[i] == -1)
            ans += toUse[ptr++];
    }
    printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    dbg("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}