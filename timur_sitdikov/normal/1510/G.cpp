#include <bits/stdc++.h>
using namespace std;


#define file "file"
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef complex<double> point;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define DEBUG 0
#define dout if(DEBUG) cout

const int MAXN = 100 + 5;

vi g[MAXN];
bool used[MAXN];
int d[MAXN], p[MAXN];
bool passed[MAXN][MAXN];
set<int> cand;
vi ans;

void dfs(int v, int from) {
    used[v] = 1;
    for (auto to : g[v]) {
        if (to == from) continue;
        d[to] = d[v] + 1;
        p[to] = v;
        dfs(to, v);
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 0 << endl;
        cout << 1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        used[i] = 0;
        for (int j = 1; j <= n; j++) {
            passed[i][j] = 0;
        }
    }
    ans.clear();
    cand.clear();

    int v;
    for (int i = 2; i <= n; i++) {
        cin >> v;
        g[v].pb(i);
        g[i].pb(v);
    }
    d[1] = 1;
    dfs(1, 1);
    int mx_v = 2;
    for (int i = 3; i <= n; i++) {
        if (d[i] > d[mx_v]) {
            mx_v = i;
        }
    }
    v = mx_v;
    ans.pb(v);
    cand.insert(v);

    k -= d[v];
    while(v != 1) {
        int to = p[v];
        passed[v][to] = passed[to][v] = 1;
        v = to;
        cand.insert(v);
        ans.pb(v);
    }
    reverse(ans.begin(), ans.end());
    while (k < 0) {
        ans.pop_back();
        k++;
    }

    while (k > 0) {
        v = *cand.begin();
        if (g[v].empty()) {
            cand.erase(cand.begin());
        }
        else {
            int to = g[v].back();
            if (!passed[v][to]) {
                if (!g[to].empty()) cand.insert(to);

                for (int j = 0; j < (int)ans.size(); j++) {
                    if (ans[j] == v) {
                        k--;
                        ans.insert(ans.begin() + j + 1, to);
                        ans.insert(ans.begin() + j + 2, v);
                        passed[to][v] = passed[v][to] = 1;
                        break;
                    }
                }
            }
            g[v].pop_back();
        }
    }
    cout << (int)ans.size() - 1 << endl;
    for (auto v : ans) cout << v << " ";
    cout << endl;
}

int main() {
    #ifdef NASTYA
        assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
    #else
    // assert(freopen(file".in", "r", stdin)); assert(freopen(file".out", "w", stdout));
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}