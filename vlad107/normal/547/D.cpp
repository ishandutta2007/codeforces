#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

using namespace std;

const int N = 2e5;
const int M = 1e6;

int n, ff, curn, ans[M];
set< pair<int, int> > g[M];
map< pair<int, int>, int > rev;
vector<int> v;

void dfs(int x) {
    while (!g[x].empty()) {
        set< pair<int, int> >::iterator it = g[x].begin();
        int id = it -> second;
        int y = it -> first;
        g[x].erase(it);
        g[y].erase(make_pair(x, id));
        dfs(y);
    }
    v.push_back(x);
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        y += N;
        g[x].insert(make_pair(y, i));
        g[y].insert(make_pair(x, i));
        rev[make_pair(x, y)] = i;
        rev[make_pair(y, x)] = i;
    }
    curn = n;
    ff = 2 * N;
    for (int i = 0; i < 2 * N; i++) {
        if (g[i].size() % 2 != 0) {
            g[i].insert(make_pair(ff, curn));
            g[ff].insert(make_pair(i, curn));
            rev[make_pair(i, ff)] = curn;
            rev[make_pair(ff, i)] = curn;
            curn++;
        }
    }
    int fst = 2 * N;
    for (int i = fst; i >= 0; i--) {
        if (!g[i].empty()) dfs(i);
    }
    for (int i = 0; i < v.size(); i++) cerr << v[i] << " ";
    cerr << endl;
    for (int i = 1; i < v.size(); i++) {
        int id = rev[make_pair(v[i - 1], v[i])];
        // cerr << id << " ";
        ans[id] = (i & 1);
        // cerr << id << endl;
    }
    // for (int i = 0; i < curn; i++) cerr << ans[i] << " ";
    // cerr << endl;
    for (int i = 0; i < n; i++) {
        if (ans[i]) putchar('b'); else putchar('r');
    }
    puts("");
}