#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const int N = 3005;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(time(0));

int T, n, m, x, y;
bool v[N];
vector<int> path;
set<int> g[N];

void gen_path(int x) {
    while(g[x].size()){
        int u = *g[x].begin();
        g[x].erase(u), g[u].erase(x);
        gen_path(u);
    }
    path.PB(x);
}

void dfs(int x) {
    v[x] = true;
    for (auto u : g[x])
        if (!v[u])
            dfs(u);
}

int main() {
    cin >> n >> m;
    rep(i, 1, m) {
        cin >> x >> y;
        g[x].insert(y), g[y].insert(x);
    }

    set<int> odd;
    rep(i, 1, n) if (g[i].size() % 2) odd.insert(i);
    if (odd.size() <= 2) {
        int start = odd.size() ? *odd.begin() : 1;
        gen_path(start);
        cout << m + 1 << endl;
        for (auto x : path)
            cout << x << " ";
        return 0;
    }

    rep(i, 1, n) {
        set<int> tmp;
        for (auto u : g[i])
            if (g[u].size() % 2)
                tmp.insert(u), odd.erase(u);
        for (auto u : tmp)
            g[i].erase(u), g[u].erase(i);
        //if remain two odd points including i, it will be erased and only the other will left
        if (odd.count(i))
            odd.erase(i);

        if (!odd.size() || odd.size() <= 2 && g[i].size() % 2 == 1) {
            //case 1: delete all edges and the graph is still connected
            memset(v, 0, sizeof v);
            dfs(i);
            bool flag = true;
            rep(j, 1, n) if (!g[j].size()) v[j] = true;
            rep(j, 1, n) if (!v[j]) flag = false;

            if (!flag && !odd.size()) {
                //case 2: restore one edge to make it connected
                set<int> nvisit;
                rep(j, 1, n) if (!v[j]) nvisit.insert(j);
                dfs(*nvisit.begin());
                flag = true;
                rep(j, 1, n) if (!v[j]) flag = false;

                if (flag) {
                    int u = 0;
                    for (auto x : tmp)
                        if (nvisit.count(x))
                            u = x;
                    if (!u)
                        flag = false;
                    else
                        g[i].insert(u), g[u].insert(i),
                            tmp.erase(u), odd.insert(u);
                }
            }

            if (flag) {
                gen_path(i);
                cout << path.size() + 1 + tmp.size() * 2 << endl;
                for (auto x : path)
                    cout << x << " ";
                cout << "-1 ";
                for (auto u : tmp)
                    cout << u << " " << i << " ";
                return 0;
            }
        }

        for (auto u : tmp)
            g[i].insert(u), g[u].insert(i), odd.insert(u);
        if (g[i].size() % 2)
            odd.insert(i);
    }
    cout << 0 << endl;
    return 0;
}