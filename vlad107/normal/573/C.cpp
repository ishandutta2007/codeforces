#include <memory.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 5e5;
const int INF = 1e9 + 19;

vector<int> g[N];
int n, cleaf[N];

void dfs(int x, int px) {
    cleaf[x] = 0;
    bool leaf = true;
    for (int i = 0; i < (int)g[x].size(); i++) {
        int y = g[x][i];
        if (y == px) continue;
        dfs(y, x);
        cleaf[x] += cleaf[y];
        leaf = false;
    }
    if (leaf) cleaf[x]++;
}

void dfs1(int x, int px) {
    int cnt = 0;
    for (int i = 0; i < (int)g[x].size(); i++) {
        int y = g[x][i];
        int cl = cleaf[y];
        if (y == px) {
            cl = cleaf[0] - cleaf[x];
            if (g[0].size() == 1) ++cl;
        } else dfs1(y, x);
        bool can = false;
        if (x == 2) {
//          cerr << x << " " << y << " " << cl << endl;
        }
        if ((cl == 1) || ((cl == 2) && (g[y].size() == 3))) can = true;
        if (!can) cnt++;
    }
    if (cnt > 2) {
        puts("No");
        exit(0);
    }
}

int main() {
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif 

    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0, -1);
    dfs1(0, -1);
    puts("Yes");
}