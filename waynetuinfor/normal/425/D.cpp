#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 5;

cc_hash_table<long long, int> cht;
vector<pair<int, int>> px[maxn], py[maxn];
int x[maxn], y[maxn], posx[maxn], posy[maxn];

inline long long f(int x, int y) {
    return x * 1ll * maxn + y;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d %d", &x[i], &y[i]);
    for (int i = 0; i < n; ++i) {
        px[x[i]].emplace_back(y[i], i);
        py[y[i]].emplace_back(x[i], i);
        cht[f(x[i], y[i])]++;
    }    
    for (int i = 0; i < maxn; ++i) {
        sort(px[i].begin(), px[i].end());
        sort(py[i].begin(), py[i].end());
    }
    for (int i = 0; i < n; ++i) {
        posx[i] = lower_bound(px[x[i]].begin(), px[x[i]].end(), make_pair(y[i], -1)) - px[x[i]].begin();
        posy[i] = lower_bound(py[y[i]].begin(), py[y[i]].end(), make_pair(x[i], -1)) - py[y[i]].begin();
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int disx = (int)px[x[i]].size() - posx[i], disy = (int)py[y[i]].size() - posy[i];
        if (disx > disy) {
            for (int j = posy[i] + 1; j < py[y[i]].size(); ++j) {
                int tx = py[y[i]][j].first;
                if (cht[f(x[i], y[i] + tx - x[i])] && cht[f(tx, y[i] + tx - x[i])]) ++ans;
            }
        } else {
            for (int j = posx[i] + 1; j < px[x[i]].size(); ++j) {
                int ty = px[x[i]][j].first;
                if (cht[f(x[i] + ty - y[i], y[i])] && cht[f(x[i] + ty - y[i], ty)]) ++ans;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}