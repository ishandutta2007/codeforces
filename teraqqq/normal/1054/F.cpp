#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cassert>

using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;

const int N = 1000;

int used[N], has_pair[N], utn, mp[N];
vi g[N];
bool print = false;

bool kuhn(int v) {
    if (used[v] == utn) return false;
    used[v] = utn;

    for (int to : g[v]) {
        if (mp[to] == -1) {
            mp[to] = v;
            return true;
        }
    }

    for (int to : g[v]) {
        if (kuhn(mp[to])) {
            mp[to] = v;
            return true;
        }
    }

    return false;
}

struct Segment {
    int x1, y1, x2, y2;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    vector<int> px, py;
    vector<pi> pt(n);

    for (auto& [x, y] : pt) {
        cin >> x >> y;
        px.push_back(x);
        py.push_back(y);
    }

    sort(px.begin(), px.end()); px.erase(unique(px.begin(), px.end()), px.end());
    sort(py.begin(), py.end()); py.erase(unique(py.begin(), py.end()), py.end());


    const int m = px.size(), k = py.size();
    vector sid(m, vi(k, -1)), vid(m, vi(k, -1));
    vector has(m, vi(k, 0)),  hid(m, vi(k, -1));

    for (auto& [x, y] : pt) {
        x = lower_bound(px.begin(), px.end(), x) - px.begin();
        y = lower_bound(py.begin(), py.end(), y) - py.begin();
        has[x][y] = true;
    }

    int hc = 0, vc = 0;
    for (int i = 0; i < m; ++i) {
        int j = 0;
        while (j < k && !has[i][j]) ++j;

        while (j < k) {
            int t = ++j;
            while (j < k && !has[i][j]) ++j;

            if (j < k) {
                hid[i][t-1] = hc;
                while (t < j) sid[i][t++] = hc;
                hc++;
            }
        }
    }

    for (int i = 0; i < k; ++i) {
        int j = 0;
        while (j < m && !has[j][i]) ++j;

        while (j < m) {
            int t = ++j;
            while (j < m && !has[j][i]) ++j;

            if (j < m) {
                vid[t-1][i] = vc;
                while (t < j) {
                    if (sid[t][i] != -1) {
                        g[sid[t][i]].push_back(vc);
                    }
                    ++t;
                }
                vc++;
            }
        }
    }

    fill(mp, mp+vc, -1);

    int flow = 0;
    for (int i = 0; i < hc; ++i) {
        utn++;
        has_pair[i] = kuhn(i);
        flow += has_pair[i];
    }

    utn++;
    for (int i = 0; i < hc; ++i) {
        if (!has_pair[i]) kuhn(i);
    }

    vector<char> hfr(hc, false), vfr(vc, false);
    for (int i = 0; i < hc; ++i) {
        if (used[i] == utn) hfr[i] = true;
    }
    for (int i = 0; i < vc; ++i) {
        if (mp[i] == -1 || used[mp[i]] != utn) vfr[i] = true;
    }

    for (int i = 0; i < hc; ++i) {
        for (int j : g[i]) assert(!hfr[i] || !vfr[j]);
    }

    vector<Segment> h_lines;
    for (int i = 0; i < m; ++i) {
        int j = 0;
        while (j < k && !has[i][j]) ++j;

        int prv = j;
        while (j < k) {
            bool nw = false;
            if (hid[i][j] < 0 || !hfr[hid[i][j]]) {
                h_lines.push_back({ i, prv, i, j });
                nw = true;
            }

            ++j;
            while (j < k && !has[i][j]) ++j;
            if (nw) prv = j;
        }
    }

    vector<Segment> v_lines;
    for (int i = 0; i < k; ++i) {
        int j = 0;
        while (j < m && !has[j][i]) ++j;

        int prv = j;
        while (j < m) {
            bool nw = false;
            if (vid[j][i] < 0 || !vfr[vid[j][i]]) {
                v_lines.push_back({ prv, i, j, i });
                nw = true;
            }

            ++j;
            while (j < m && !has[j][i]) ++j;
            if (nw) prv = j;
        }
    }

    cout << v_lines.size() << '\n';
    for (auto [x1, y1, x2, y2] : v_lines) cout << px[x1] << ' ' << py[y1] << ' ' << px[x2] << ' ' << py[y2] << '\n';
    cout << h_lines.size() << '\n';
    for (auto [x1, y1, x2, y2] : h_lines) cout << px[x1] << ' ' << py[y1] << ' ' << px[x2] << ' ' << py[y2] << '\n';
}