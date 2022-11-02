#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

const int BASE = 1e9 + 7;

int n;
vector<int> pr, f, pref, suff, ff;
vector< vector<int> > g;

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    pr.resize(n);
    f.assign(n, 1);
    pref.resize(n);
    suff.resize(n);
    g.resize(n);
    ff.resize(n);
    for (int i = 1; i < n; i++) {
        scanf("%d", &pr[i]); --pr[i];
        g[pr[i]].push_back(i);
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int u: g[i]) {
            pref[u] = f[i];
            f[i] = (f[i] * 1LL * (f[u] + 1)) % BASE;
        }
        int cur = 1;
        for (int j = (int)g[i].size() - 1; j >= 0; j--) {
            suff[g[i][j]] = cur;
            cur = (cur * 1LL * (f[g[i][j]] + 1)) % BASE;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int u: g[i]) {
            ff[u] = (pref[u] * 1LL * (ff[i] + 1)) % BASE;
            ff[u] = (suff[u] * 1LL * ff[u]) % BASE;
        }
        printf("%d ", (int) ((f[i] * 1LL * (ff[i] + 1)) % BASE));
    }
}