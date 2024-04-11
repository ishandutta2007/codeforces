#include <bits/stdc++.h>
using namespace std;

int parent[1000005];
int rnk[1000005];
vector<int> elem[1000005];
int getparent(int t)
{
    return t == parent[t] ? t : parent[t] = getparent(parent[t]);
}
void merge(int a, int b)
{
    a = getparent(a); b = getparent(b);
    if (a == b) return;
    if (rnk[a] < rnk[b]) swap(a, b);
    else if (rnk[a] == rnk[b]) ++rnk[a];
    parent[b] = a;
}

int dat[1000005];

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 1; i <= n; i++) scanf("%d",&dat[i]);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        merge(a, b);
    }
    for (int i = 1; i <= n; i++)
    {
        elem[getparent(i)].push_back(dat[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (i != getparent(i)) continue;
        sort(elem[i].begin(), elem[i].end());
    }
    for (int i = 1; i <= n; i++)
    {
        auto &vt = elem[getparent(i)];
        printf("%d ", vt.back());
        vt.pop_back();
    }
    printf("\n");
}