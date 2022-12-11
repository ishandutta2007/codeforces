#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
const int N = 2e5 + 10;
int n, m;
vector<int> e[N];
int v[N][2];
int vis[N], dir[N];


int co[N];
int ansa[N], ansb[N];

void DFS(int st) {
    queue<int> q;

    vis[st] = 1;
    q.push(st);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for(auto i : e[x]) {
            int cdir = x == v[i][1];
            int y = v[i][cdir ^ 1];
            if (dir[i] == -1) dir[i] = cdir;
            if (cdir == dir[i] && !vis[y]) {
                vis[y] = 1;
                q.push(y);
            }
        }
    }
}
void toposorta(int x, int &pos) {
    for(auto i : e[x]) {
        int cdir = x == v[i][1];
        int y = v[i][cdir ^ 1];
        if (cdir == dir[i]) {
            if (!ansa[y]) toposorta(y, pos);
        }
    }
    ansa[x] = pos--;
    //cout << x << "x" << ansa[x] << '\n';
}

void toposortb(int x) {
    ansb[x] = n;
    for(auto i : e[x]) {
        int cdir = x == v[i][1];
        int y = v[i][cdir ^ 1];
        if (cdir == dir[i]) {
            if (!ansb[y]) toposortb(y);
            ansb[x] = min(ansb[x], ansb[y] - 1);
        }
    }
}

/*
void toposortb(int st) {
    queue<int> q;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for(auto i : e[x]) {
            int cdir = x == v[i][1];
            int y = v[i][cdir ^ 1];
            if (dir[i] == -1) dir[i] = cdir;
            if (cdir == dir[i]) {
                ansb[y] = max(ansb[y], ansb[x] + 1);
                if (!vis[y]) {
                    vis[y] = 1;
                    q.push(y);
                }
            }
        }
    }
}
*/

set<ii> eset;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;


        if (x > y) swap(x, y);
        v[i][0] = x, v[i][1] = y;
        e[x].push_back(i);
        e[y].push_back(i);
        eset.insert(ii(x, y));
    }

    int st = -1, en = -1;
    for(int x = 1; x <= n; x++) {
        for(int y = x + 1; y <= n; y++) {
            if (!eset.count(ii(x, y))) {
                st = x, en = y;
                break;
            }
        }
    }
    if (st == -1) {
        cout << "NO";
        return 0;
    }
    for(auto i : e[st]) {
        int cdir = st == v[i][1];
        dir[i] = cdir;
    }
    for(auto i : e[en]) {
        int cdir = en == v[i][1];
        dir[i] = cdir;
    }
    for(int i = 1; i <= n; i++) if (!ansb[i])
        toposortb(i);
    
    int pn = n;
    for(int i = 1; i <= n; i++) if (!ansa[i])
        toposorta(i, pn);

    for(int i = 1; i <= n; i++) co[ansb[i]]++;
    
    if (count(co + 1, co + n + 1, 0)) {
        cout << "YES\n";
        for(int i = 1; i <= n; i++) cout << ansa[i] << " ";
        cout << '\n';
        for(int i = 1; i <= n; i++) cout << ansb[i] << " ";
        cout << '\n';
    } else cout << "NO";
}