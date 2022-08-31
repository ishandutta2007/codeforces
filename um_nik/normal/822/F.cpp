#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 111;
vector<pii> g[N];

void printAns(int id, int v, int u, double x) {
    if (x >= 1) {
        swap(v, u);
        x -= 1;
    }
    x = 1 - x;
    printf("1 %d %d %d %.12lf\n", id, u, v, x);
}

void dfs(int v, int par, double x)
{
    for (pii e : g[v]) {
        if (e.first == par) continue;
        x += 2. / (int)g[v].size();
        if (x >= 2) x -= 2;
        printAns(e.second, v, e.first, x);
        double y = x + 1;
        if (y >= 2) y -= 2;
        dfs(e.first, v, y);
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        g[v].push_back(mp(u, i));
        g[u].push_back(mp(v, i));
    }
    printf("%d\n", n - 1);
    double x = 0;
    for (pii e : g[1]) {
        printAns(e.second, 1, e.first, x);
        double y = x + 1;
        if (y >= 2) y -= 2;
        dfs(e.first, 1, y);
        x += 2. / (int)g[1].size();
    }

    return 0;
}