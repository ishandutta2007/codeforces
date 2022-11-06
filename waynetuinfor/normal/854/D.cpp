#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxt = 1e6 + 10;
const long long inf = 1e15 + 1;
vector<pair<pair<int, int>, int>> rt, go;
int curmin[maxn];
long long sf[maxt];
bool ok[maxt];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int d, f, t, c; cin >> d >> f >> t >> c;
        if (f == 0) rt.push_back(make_pair(make_pair(d, c), t));
        else go.push_back(make_pair(make_pair(d, c), f));
    }
    sort(rt.begin(), rt.end()); sort(go.begin(), go.end());
    reverse(rt.begin(), rt.end());
    fill(curmin, curmin + maxn, maxt);
    set<int> in;
    int ind = 0;
    for (int t = maxt - 2; t >= 1; --t) {
        sf[t] = sf[t + 1]; ok[t] = ok[t + 1];
        while (ind < rt.size() && rt[ind].first.first >= t) {
            if (curmin[rt[ind].second] != maxt) sf[t] -= curmin[rt[ind].second];
            curmin[rt[ind].second] = min(curmin[rt[ind].second], rt[ind].first.second);
            sf[t] += curmin[rt[ind].second];
            in.insert(rt[ind].second);
            ++ind;
        }
        if (in.size() == n) ok[t] = true;
    }
    long long pf = 0;
    in.clear(); ind = 0;
    fill(curmin, curmin + maxn, maxt);
    long long ans = inf;
    bool can = false;
    for (int t = 1; t < maxt; ++t) {
        while (ind < go.size() && go[ind].first.first <= t) {
            if (curmin[go[ind].second] != maxt) pf -= curmin[go[ind].second];
            curmin[go[ind].second] = min(curmin[go[ind].second], go[ind].first.second);
            pf += curmin[go[ind].second];
            in.insert(go[ind].second);
            ++ind;
        }
        if (in.size() == n) can = true;
        if (t + k + 1 < maxt && can && ok[t + k + 1]) ans = min(ans, pf + sf[t + k + 1]);
    }
    if (ans == inf) ans = -1;
    cout << ans << endl;
    return 0;
}