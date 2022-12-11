#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair
const int BLOCK = 5000;
const int LOG = 18;
const int INF = (int)1e9;
const int N = (int)2e5 + 10;
struct Event
{
    int t, v;
    Event () {}
    Event (int t, int v) : t(t), v(v) {}
} event[N];

int euler[N];
int sparse[LOG][N];
int tin[N];
vector <int> g[N];
int h[N];
int firstPos[N], lastPos[N];
int distUp[N], distDown[N];
int firstMin[N], secondMin[N];
int indE;
int used[N];
int cc = 1;
int d[N];
bool color[N];
int tme = 0;

void calcSparse()
{
    for (int i = 0; i < LOG; i++)
    {
        for (int s = 0; s <= indE - (1 << i); s++)
        {
            if (i == 0)
                sparse[i][s] = euler[s];
            else
            {
                int a = sparse[i - 1][s];
                int b = sparse[i - 1][s + (1 << (i - 1))];
                if (tin[a] < tin[b])
                    sparse[i][s] = a;
                else
                    sparse[i][s] = b;
            }
        }
    }
}

void calcH()
{
    h[1] = 0;
    for (int i = 2; i < N; i++)
        h[i] = h[i / 2] + 1;
}

void calcInfo(int v)
{
    firstPos[v] = indE;
    tin[v] = tme++;
    euler[indE++] = v;
    used[v] = cc;
    for (int i = 0; i < (int)g[v].size(); i++)
    {   
        int to = g[v][i];
        if (used[to] != cc)
        {
            d[to] = d[v] + 1;
            calcInfo(to);
            lastPos[v] = indE;
            euler[indE++] = v;
        }
    }
}

inline int getLca(int a, int b)
{                 
    int posA = firstPos[a];
    int posB = firstPos[b];
    if (posA > posB)      
    {
        int tmp = posA;
        posA = posB;
        posB = tmp;
    }
    int t = h[posB - posA + 1];
    int fP = sparse[t][posA];
    int sP = sparse[t][posB - (1 << t) + 1];
    if (tin[fP] < tin[sP])
        return fP;
    return sP;
}
                    
void calcDown(int v)
{
    used[v] = cc;
    if (color[v])
        distDown[v] = 0;
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int to = g[v][i];
        if (used[to] != cc)
        {
            calcDown(to);
            distDown[v] = min(distDown[v], distDown[to] + 1);
            if (distDown[to] < firstMin[v])
            {
                secondMin[v] = firstMin[v];
                firstMin[v] = distDown[to];
            }
            else if (distDown[to] < secondMin[v])
                secondMin[v] = distDown[to];
        }
    }                    
}

void calcUp(int v, int curD)
{       
    if (color[v])
        curD = 0;
    used[v] = cc;                   
    distUp[v] = curD;           
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int to = g[v][i];
        if (used[to] != cc)
        {
            int curT = firstMin[v];
            if (distDown[to] == firstMin[v])
                curT = secondMin[v];
            calcUp(to, min(curD + 1, curT + 2)); 
        }
    }
}

inline int getDist(int a, int b)
{
    int l = getLca(a, b);
    return d[a] + d[b] - 2 * d[l];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    calcInfo(1);            
    calcSparse();
    calcH();                       

    event[0] = Event(1, 1);
    for (int i = 1; i <= m; i++)
    {
        int t, v;
        scanf("%d%d", &t, &v);
        event[i] = Event(t, v);
    }
    m++;
    color[1] = 1;        
    fill(distUp, distUp + n + 1, INF);
    fill(distDown, distDown + n + 1, INF);
    fill(firstMin, firstMin + n + 1, INF);
    fill(secondMin, secondMin + n + 1, INF);
    
    for (int i = 0; i < m; i += BLOCK)
    {        
        cc++;
        calcDown(1);     
        cc++;
        calcUp(1, 0);
        for (int s = i; s < min(i + BLOCK, m); s++)
        {
            if (event[s].t == 2)
            {
                int curV = event[s].v;
                int ans = min(distUp[curV], distDown[curV]);
                for (int q = i; q < s; q++)
                {
                    if (event[q].t == 1) 
                    {
                        ans = min(ans, getDist(event[q].v, curV));
                    }
                }
                printf("%d\n", ans);
            }
            else
                color[event[s].v] = 1;
        }
    }

    return 0;
}