#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int n, V, e, par[300];
Int a[300], b[300];
int adj[300][300];

bool visited[300];
Int a2[300], req2[300];
void dfs(int u, vector<int>& comp, vector<int>& eu, vector<int>& ev)
{
    visited[u] = true;
    comp.push_back(u);
    a2[u] = a[u];
    req2[u] = b[u];
    par[u] = -1;
    for (int i = 0; i < n; ++i) {
        if (adj[u][i] && !visited[i]) {
            dfs(i, comp, eu, ev);
            eu.push_back(u); ev.push_back(i);
            req2[u] += req2[i];
            a2[u] += a2[i];
            par[i] = u;
        }
    }
}

void trans(int u, int v, Int lim, vector<int>& sx, vector<int>& sy, vector<int>& sd)
{
    Int am = max(0LL, min(lim, min(V - a[v], a[u])));
    if (am == 0) return;
    sx.push_back(u);
    sy.push_back(v);
    sd.push_back(am);
    a[u] -= am; a[v] += am;
    for (int uu = u; uu != -1; uu = par[uu]) {
        a2[uu] -= am;
    }
    for (int vv = v; vv != -1; vv = par[vv]) {
        a2[vv] += am;
    }
}

bool solve(vector<int> c, vector<int> eu, vector<int> ev, vector<int>& sx, vector<int>& sy, vector<int>& sd)
{
    Int req = 0, tot = 0;
    for (int i = 0; i < c.size(); ++i) {
        req += b[c[i]];
        tot += a[c[i]];
    }
    // cerr<<req<<' ' <<tot<<endl;
    if (req != tot) {
        return false;
    }
    for (int i = 0; i < 2 * c.size(); ++i) {
        for (int j = 0; j < eu.size(); ++j) {
            int u = eu[j], v = ev[j];
            // cerr << a2[v] << ' ' <<req2[v] << endl;
            if (a2[v] > req2[v]) {
                trans(v, u, a2[v] - req2[v], sx, sy, sd);
            } else if (a2[v] < req2[v]) {
                trans(u, v, req2[v] - a2[v], sx, sy, sd);
            }
        }
    }
    return true;
}

int main()
{
    cin >> n >> V >> e;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < e; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x][y] = adj[y][x] = 1;
    }

    vector<int> sx, sy, sd;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            vector<int> c, eu, ev;
            dfs(i, c, eu, ev);
            if (!solve(c, eu, ev, sx, sy, sd)) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << sx.size() << endl;
    for (int i = 0; i < sx.size(); ++i) {
        cout << sx[i]+1 << ' ' <<sy[i]+1 << ' ' << sd[i]<<endl;
    }

    return 0;
}