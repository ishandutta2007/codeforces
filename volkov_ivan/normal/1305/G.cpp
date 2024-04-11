#include <iostream>
#include <cstring>

using namespace std;

const int N = 1 << 18;
int sz[N], par[N], cnt[N], a[N], best[N];

int get_par(int v) {
    if (par[v] == v) return v;
    par[v] = get_par(par[v]);
    return par[v];
}

bool merge(int v, int u) {
    v = get_par(v);
    u = get_par(u);
    if (u == v) return 0;
    if (sz[u] > sz[v]) {
        sz[u] += sz[v];
        par[v] = u;
    } else {
        sz[v] += sz[u];
        par[u] = v;
    }
    return 1;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    memset(best, 0, sizeof(best));
    long long res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (cnt[a[i]]++ == 0) res -= a[i];
    }
    for (int i = 0; i < N; i++) {
        sz[i] = 1;
        par[i] = i;
    }
    cnt[0]++;
    for (int i = N - 1; i >= 1; i--) {
        //cout << i << endl;
        for (int j = i; j >= 0; j = (j - 1) & i) {
            int jj = j ^ i;
            if (jj > j) break;
            if (cnt[j] != 0 && cnt[jj] != 0) {
                best[jj] = max(best[jj], j);
                best[j] = max(best[j], jj);
                if (merge(j, jj)) res += i;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (cnt[i] > 1) res += (cnt[i] - 1) * 1ll * best[i];
    }
    cout << res << endl;
}