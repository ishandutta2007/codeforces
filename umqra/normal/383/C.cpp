#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

const int N = (int)2e5 + 100;
const int BLOCK = 2000;

struct Query
{
    int t, v, val;
    Query () {}
    Query (int t, int v, int val) : t(t), v(v), val(val) {}
} q[N];
int indQ = 0;
int listQ[N];

vector <int> g[N];
int h[N];
int tin[N], tout[N];
int add[N];
int a[N], saveA[N];
int tme = 0;

void createTree(int v, int sumE, int sumO, int par)
{           
    sumE += add[v];
    a[v] += sumE - sumO;
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int to = g[v][i];
        if (to != par)
        {
            createTree(to, sumO, sumE, v);
        }
    }
}

void calcInfo(int v, int par)
{
    tin[v] = tme++;
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int to = g[v][i];
        if (to != par)
        {
            h[to] = h[v] + 1;
            calcInfo(to, v);
        }
    }
    tout[v] = tme++;
}

inline bool isPar(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        saveA[i] = a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }   
    calcInfo(0, -1);

    for (int i = 0; i < m; i++)
    {
        int t, x;
        scanf("%d%d", &t, &x);
        x--;
        int val = 0;
        if (t == 1)
            scanf("%d", &val);
        q[i] = Query(t, x, val);        
    }

    for (int i = 0; i < m; i += BLOCK)
    {                
        for (int s = 0; s < n; s++)
        {
            a[s] = saveA[s];
            add[s] = 0;
        }
        for (int s = 0; s < i; s++)
        {
            if (q[s].t == 1)
                add[q[s].v] += q[s].val;
        }                                       
        createTree(0, 0, 0, -1);
        indQ = 0;
        int bord = min(i + BLOCK, m);
        for (int s = i; s < bord; s++)
        {
            if (q[s].t == 1)
                listQ[indQ++] = s;
            else
            {
                int v = q[s].v;
                int ans = a[v];
                for (int p = 0; p < indQ; p++)
                {
                    int curInd = listQ[p];
                    if (isPar(q[curInd].v, v))
                    {
                        int d = h[v] - h[q[curInd].v];
                        if (d & 1)
                            ans -= q[curInd].val;
                        else
                            ans += q[curInd].val;                                                       
                    }
                }
                printf("%d\n", ans);
            }
        }
    }

    return 0;
}