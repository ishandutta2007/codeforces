#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
#ifdef UMQRA
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
    #define getTime() fprintf(stderr, "Running time:%.3lf seconds\n", (double)(clock()) / CLOCKS_PER_SEC)
#else
    #define eprintf(...)
    #define getTime()
#endif
#define mp make_pair
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

const int pow2 = (1 << 17);
const int N = (int)1e5 + 100;
struct SegmentTree
{
    int tree[pow2 * 2];
    int d[pow2 * 2];
    void build()
    {
        for (int i = 0; i < pow2 * 2; i++)
        {
            tree[i] = 0;
            d[i] = 0;
        }
    }
    void push(int v)
    {
        if (d[v] != 0)
        {
            tree[2 * v] += d[v];
            tree[2 * v + 1] += d[v];
            d[2 * v] += d[v];
            d[2 * v + 1] += d[v];
            d[v] = 0;
        }
    }
    void addVal(int a, int b, int val, int v = 1, int l = 0, int r = pow2 - 1)
    {
        if (l >= a && r <= b)
        {                                  
            tree[v] += val;
            d[v] += val;
            return;
        }
        if (l > b || r < a)
            return;
        push(v);
        int m = (l + r) / 2;
        addVal(a, b, val, 2 * v, l, m);
        addVal(a, b, val, 2 * v + 1, m + 1, r);
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
    int getVal(int pos, int v = 1, int l = 0, int r = pow2 - 1)
    {
        if (l == r)
            return tree[v];
        push(v);
        int m = (l + r) / 2;
        if (pos <= m)
            return getVal(pos, 2 * v, l, m);
        else
            return getVal(pos, 2 * v + 1, m + 1, r);
    }
    int getMax()
    {
        return tree[1];
    }
} tree;

int ans = 0;
vector <int> g[N];
int tin[N];
int maxTin[N];
int tme = 0;
int listP[N];
int startDist[N];
bool usedP[N];
int p[N];
int indList = 0;
int D;

void dfs(int v, int dist = 0, int par = -1)
{          
    tin[v] = tme++;
    maxTin[v] = tin[v];
    if (usedP[v])
    {
        listP[indList++] = v;
        startDist[indList - 1] = dist;
    }
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int to = g[v][i];
        if (to != par)
        {
            dfs(to, dist + 1, v);
            maxTin[v] = max(maxTin[v], maxTin[to]);
        }
    }
}

void calcVertex(int v, int par = -1)
{
    if (tree.getMax() <= D)
        ans++;                    
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int to = g[v][i];                            
        if (to != par)
        {                  
            int l = -1, r = indList;
            while (r - l > 1)
            {
                int m = (l + r) / 2;
                if (tin[listP[m]] >= tin[to])
                    r = m;
                else
                    l = m;
            }
            int leftB = r;
            l = -1, r = indList;
            while (r - l > 1)
            {
                int m = (l + r) / 2;
                if (tin[listP[m]] <= maxTin[to])
                    l = m;
                else
                    r = m;
            }
            int rightB = l;
            tree.addVal(0, indList - 1, 1);
            if (leftB <= rightB)
                tree.addVal(leftB, rightB, -2);         
            calcVertex(to, v);
            tree.addVal(0, indList - 1, -1);
            if (leftB <= rightB)
                tree.addVal(leftB, rightB, 2);
        }
    }
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
       
    tree.build();
    int n, m;
    scanf("%d%d%d", &n, &m, &D);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &p[i]);
        usedP[p[i]] = 1;
    }
    for (int i = 0; i < n - 1; i++) 
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);
    for (int i = 0; i < indList; i++)
        tree.addVal(i, i, startDist[i]);
                
    calcVertex(1);
    printf("%d", ans);

    return 0;
}