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

typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ull, ull> pll;
#define mp make_pair

const ull P = 210011;
const int N = 100002;

int myRand()
{
    return rand() ^ (rand() << 15);
}

struct Node
{
    int x;
    int y;
    int l, r;
    pll val;

    Node() : x(), y(), l(-1), r(-1), val(mp((ull)0, (ull)1)) {}
    Node(int _x) : x(_x), y(myRand()), l(-1), r(-1), val(mp((ull)_x, P)) {}
};
Node treap[2 * N];
int treapSz = 0;

pll mergeHashes(pll L, pll R)
{
    return mp(L.first * R.second + R.first, L.second * R.second);
}

pll getHash(int v)
{
    return v == -1 ? mp((ull)0, (ull)1) : treap[v].val;
}

int update(int v)
{
    if (v == -1) return v;
    treap[v].val = mergeHashes(mergeHashes(getHash(treap[v].l), mp((ull)treap[v].x, P)), getHash(treap[v].r));
    return v;
}

int merge(int L, int R)
{
    if (L == -1) return R;
    if (R == -1) return L;
    if (treap[L].y > treap[R].y)
    {
        treap[L].r = merge(treap[L].r, R);
        return update(L);
    }
    else
    {
        treap[R].l = merge(L, treap[R].l);
        return update(R);
    }
}

void split(int v, int x, int &L, int &R)
{
    if (v == -1)
    {
        L = R = -1;
        return;
    }
    if (treap[v].x < x)
    {
        split(treap[v].r, x, treap[v].r, R);
        L = update(v);
    }
    else
    {
        split(treap[v].l, x, L, treap[v].l);
        R = update(v);
    }
}

pll getHashWithout(int &v, int x)
{
    int L, M1, M2, M3, R;
    split(v, x, L, R);
    split(R, x + 1, M2, R);
    if (M2 == -1) throw;
    M1 = treap[M2].l, M3 = treap[M2].r;
    treap[M2].l = treap[M2].r = -1;
    M2 = update(M2);
    v = merge(merge(L, M1), merge(M3, R));
    pll res = getHash(v);
    split(v, x, L, R);
    v = merge(L, merge(M2, R));
    return res;
}

void treapInsert(int &v, int x)
{
    treap[treapSz++] = Node(x);
    int L, R;
    split(v, x, L, R);
    v = merge(L, merge(treapSz - 1, R));
    return;
}

int n;
int m = 1;
vector<pii> g[N];
int deg[N];
int ed[N][2];
int a[N][2];
int q[2 * N];
int topQ;
bool usedV[N];
int sets[N];
map<ull, int> toId;
int cnt[2 * N];
int curBal = 0;
int bestVal = -1;
int ans = -1;

int getId(ull x)
{
    if (toId.count(x) > 0) return toId[x];
    toId[x] = m;
    return m++;
}

void add(int x)
{
    if (cnt[x] == 0)
        curBal++;
    cnt[x]++;
}
void remove(int x)
{
    cnt[x]--;
    if (cnt[x] == 0)
        curBal--;
}

void dfs1(int v, int par)
{
    for (pii eid : g[v])
    {
        int u = ed[eid.first][1 ^ eid.second];
        if (u == par) continue;
        add(a[eid.first][eid.second]);
        dfs1(u, v);
    }
    return;
}

void dfs2(int v, int par)
{
    if (curBal > bestVal)
    {
        bestVal = curBal;
        ans = v;
    }
    for (pii eid : g[v])
    {
        int u = ed[eid.first][1 ^ eid.second];
        if (u == par) continue;
        remove(a[eid.first][eid.second]);
        add(a[eid.first][1 ^ eid.second]);
        dfs2(u, v);
        remove(a[eid.first][1 ^ eid.second]);
        add(a[eid.first][eid.second]);
    }
    return;
}

int main()
{
    //freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    
    scanf("%d", &n);
    if (n == 1)
    {
        printf("1\n");
        return 0;
    }
    

    //n = 100000;
    
    for (int i = 1; i < n; i++)
    {
          
        scanf("%d%d", &ed[i][0], &ed[i][1]);
        ed[i][0]--;
        ed[i][1]--;
        
        /*
        ed[i][0] = 0;
        ed[i][1] = i;
        */

        deg[ed[i][0]]++;
        deg[ed[i][1]]++;
        g[ed[i][0]].push_back(mp(i, 0));
        g[ed[i][1]].push_back(mp(i, 1));
    }
    for (int i = 1; i < n; i++)
        a[i][0] = a[i][1] = -1;
    for (int i = 0; i < n; i++)
        sets[i] = -1;
    for (int i = 0; i < n; i++)
        if (deg[i] == 1)
            q[topQ++] = i;
    for (int k = 0; k < topQ; k++)
    {
        int v = q[k];
        if (deg[v] > 1) throw;
        if (deg[v] == 1)
        {
            for (int i = 0; i < (int)g[v].size(); i++)
            {
                pii e = g[v][i];
                if (a[e.first][e.second] == -1)
                {
                    pll h = getHash(sets[v]);
                    ull hh = h.first + h.second;
                    a[e.first][1 ^ e.second] = getId(hh);
                    int u = ed[e.first][1 ^ e.second];
                    treapInsert(sets[u], a[e.first][1 ^ e.second]);
                    deg[u]--;
                    if (deg[u] <= 1)
                        q[topQ++] = u;
                }
            }
            continue;
        }
        if (usedV[v]) continue;
        usedV[v] = 1;
        for (int i = 0; i < (int)g[v].size(); i++)
        {
            pii e = g[v][i];
            if (a[e.first][1 ^ e.second] == -1)
            {
                int x = a[e.first][e.second];
                if (x == -1) throw;
                pll h = getHashWithout(sets[v], x);
                ull hh = h.first + h.second;
                a[e.first][1 ^ e.second] = getId(hh);
                int u = ed[e.first][1 ^ e.second];
                treapInsert(sets[u], a[e.first][1 ^ e.second]);
                deg[u]--;
                if (deg[u] <= 1)
                    q[topQ++] = u;
            }
        }
    }

    /*
    for (int i = 1; i < n; i++)
        printf("%d %d\n", a[i][0], a[i][1]);
    */
    
    dfs1(0, -1);
    dfs2(0, -1);
    printf("%d\n", ans + 1);

    return 0;
}