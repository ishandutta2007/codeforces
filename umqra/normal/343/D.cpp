#include <iostream>
#include <cstdio>
#include <algorithm>    
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define X first
#define Y second
#define mp make_pair

const int pow2 = (1 << 20);
const int N = (int)5e5 + 100;

struct SegmentTree
{
    int tree[pow2 * 2]; 
    int d[pow2 * 2];
    void init()
    {
        for (int i = 0; i < pow2 * 2; i++)
        {
            tree[i] = d[i] = 0;
        }
    }
    void push(int v)
    {
        if (d[v] != 0)
        {
            tree[2 * v] = d[v];
            tree[2 * v + 1] = d[v];
            d[2 * v + 1] = d[v];    
            d[2 * v] = d[v];
            d[v] = 0;
        }
    }
    void setVal(int a, int b, int val, int v = 1, int l = 0, int r = pow2 - 1)
    {
        if (l >= a && r <= b)
        {
            tree[v] = val;
            d[v] = val;
            return;
        }
        if (l > b || r < a)
            return;
        push(v);
        int m = (l + r) / 2;
        setVal(a, b, val, 2 * v, l, m);
        setVal(a, b, val, 2 * v + 1, m + 1, r);
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
    int getMax(int a, int b, int v = 1, int l = 0, int r = pow2 - 1)
    {
        if (l >= a && r <= b)
            return tree[v];
        if (l > b || r < a)
            return 0;
        push(v);
        int m = (l + r) / 2;
        return max(getMax(a, b, 2 * v, l, m), getMax(a, b, 2 * v + 1, m + 1, r));
    }
} treeFull, treeEmpt;
bool used[N];
vector <int> g[N];
int indE;
int fPos[N], sPos[N];

void dfs(int v)
{
    used[v] = 1;
    fPos[v] = indE++;          
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int to = g[v][i];   
        if (!used[to])
        {
            dfs(to);
        }
    }
    sPos[v] = indE++;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    treeFull.init();
    treeEmpt.init();

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);     
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int t, v;
        scanf("%d%d", &t, &v);
        if (t == 1)
        {
            int l = fPos[v];
            int r = sPos[v];
            treeFull.setVal(l, r, i + 1);
        }
        else if (t == 2)
        {
            treeEmpt.setVal(fPos[v], fPos[v], i + 1);
        }
        else
        {
            int l = fPos[v], r = sPos[v];
            int a = treeFull.getMax(l, l);
            int b = treeEmpt.getMax(l, r);
            if (a > b)
                puts("1");
            else
                puts("0");
        }
    }

    return 0;
}