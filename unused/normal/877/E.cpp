#pragma GCC target("arch=ivybridge")
#include <bits/stdc++.h>
using namespace std;

// example implementation of sum tree
const int TSIZE = 262144; // always 2^k form && n <= TSIZE
int segtree[TSIZE * 2];
bool prop[TSIZE * 2];

void seg_relax(int nod, int l, int r) {
    if (prop[nod] == false) return;
    if (l < r) {
        int m = (l + r) >> 1;
        segtree[nod << 1] = m - l + 1 - segtree[nod << 1];
        prop[nod << 1] ^= true;
        segtree[nod << 1 | 1] = r - m - segtree[nod << 1 | 1];
        prop[nod << 1 | 1] ^= true;
    }
    prop[nod] = false;
}

int seg_query(int nod, int l, int r, int s, int e) {
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return segtree[nod];
    seg_relax(nod, l, r);
    int m = (l + r) >> 1;
    return seg_query(nod << 1, l, m, s, e) + seg_query(nod << 1 | 1, m + 1, r, s
            , e);
}

void seg_update(int nod, int l, int r, int s, int e) {
    if (r < s || e < l) return;
    if (s <= l && r <= e) {
        segtree[nod] = r - l + 1 - segtree[nod];
        prop[nod] ^= true;
        return;
    }
    seg_relax(nod, l, r);
    int m = (l + r) >> 1;
    seg_update(nod << 1, l, m, s, e);
    seg_update(nod << 1 | 1, m + 1, r, s, e);
    segtree[nod] = segtree[nod << 1] + segtree[nod << 1 | 1];
}

vector<int> graph[200005];
int st[200005], fin[200005];
int vtime;

void dfs(int t)
{
    st[t] = vtime++;
    for (int nxt : graph[t]) dfs(nxt);
    fin[t] = vtime;
}

int main()
{
    int n;scanf("%d",&n);
    for (int i = 2; i <= n; i++)
    {
        int x; scanf("%d",&x); graph[x].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        int x; scanf("%d",&x); if (x == 1) seg_update(1, 0, TSIZE - 1, st[i], st[i]);
    }
    int q;
    scanf("%d",&q);
    while (q--)
    {
        char cmd[10]; int x;
        scanf("%s%d",cmd,&x);
        if (cmd[0] == 'g') printf("%d\n", seg_query(1, 0, TSIZE - 1, st[x], fin[x] - 1));
        else seg_update(1, 0, TSIZE - 1, st[x], fin[x] - 1);
    }
}