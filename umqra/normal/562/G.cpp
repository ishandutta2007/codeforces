#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second 
#define mp make_pair

const int N = 30000 + 10;
const int E = 2 * 8 * N + 100;
const int V = N;

int a[E], b[E], c[E];
pii listE[E];
bool usedNOEdge[E];
int noEulerEdges[E];
int eulerEdges[E];
int indE = 0;
int eulerSize = 0;
bool used[V];
vector <int> g[V];
vector <int> bcG[V];
int cntProcess[E];

void findNOEuler(int v, int eFrom)
{
    used[v] = 1;
    while (bcG[v].size() > 0)
    {
        int e = bcG[v].back();
        bcG[v].pop_back();
        if (usedNOEdge[e])
            continue;
        usedNOEdge[e] = usedNOEdge[e ^ 1] = 1;
        int to = listE[e].Y;
        findNOEuler(to, e);
    }
    if (eFrom != -1)
        noEulerEdges[eulerSize++] = eFrom;
}

void findEuler(int v, int eFrom)
{
    while (g[v].size() > 0)
    {
        int e = g[v].back();
        g[v].pop_back();
        int to = listE[e].Y;
        findEuler(to, e);
    }
    if (eFrom != -1)
        eulerEdges[eulerSize++] = eFrom;
}

int main()
{
#ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < N; i++)
        cntProcess[i] = 4;
    for (int i = 0; i < 4 * n; i++)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        a[i]--, b[i]--, c[i]--;
        listE[indE++] = mp(b[i], c[i]);
        bcG[b[i]].push_back(indE - 1);
        listE[indE++] = mp(c[i], b[i]);
        bcG[c[i]].push_back(indE - 1);
    }
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
            findNOEuler(i, -1);
    }
    for (int i = 0; i < 8 * n; i++)
    {
        listE[2 * i] = mp(a[i], b[i]);
        listE[2 * i + 1] = mp(a[i], c[i]);
    }
    for (int i = 0; i < eulerSize; i++)
    {
        int e = noEulerEdges[i];  
        g[a[e / 2]].push_back(e);
    }
    memset(used, 0, sizeof(used));
    eulerSize = 0;
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
            findEuler(i, -1);
    }
    puts("YES");
    for (int i = 0; i < eulerSize; i++)
    {
        int id = eulerEdges[i] / 2;
        cntProcess[a[id]]--;
        cntProcess[b[id]]++;
        cntProcess[c[id]]++;
        if (cntProcess[b[id]] > 9 || cntProcess[c[id]] > 9)
            throw;
        printf("%d ", id + 1);
    }

    return 0;
}