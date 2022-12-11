#include <bits/stdc++.h>
using namespace std;


#define FORI(i, n) for(int i = 0; i < n; i++)
#define N ((2 << 22) + 5)
#define pb push_back
int t[N];
int ord[N];
int nord;
int n;
vector<bool> ex;
vector<bool> vis;
int b;

void dfs1 (int v) {
    vis[v] = true;
    if(ex[v])
    {
        int w;
        if((v & 1) == 0) w = v ^ 1;
        else w = ((2 << b) - 1) ^ v;
        if(!vis[w]) dfs1(w);
        if(v & 1)
        {
            for(int i = 1; i <= b; i++)
                if((v & (1 << i)) == 0)
                {
                    w = v ^ (1 << i);
                    if(!vis[w]) dfs1(w);
                }
        }
    }
//     printf("%d ", v);
//     puts("");
    ord[nord++] = v;
}

void dfs2(int v, int k)
{
    vis[v] = true;
    t[v] = k;
    if(ex[v])
    {
        int w;
        if(v & 1) w = v ^ 1;
        else w = ((2 << b) - 1) ^ v;
        if(!vis[w]) dfs2(w, k);
        if(v & 1)
        {
            for(int i = 1; i <= b; i++)
                if(v & (1 << i))
                {
                    w = v ^ (1 << i);
                    if(!vis[w]) dfs2(w, k);
                }
        }
    }
}

void scc() {
    vis.resize(n);
    for(int i = 0; i < n; i++)
        if(!vis[i])
            dfs1(i);
    vis.clear();
    vis.resize(n);
    for(int i = n-1; i >= 0; i--)
        if(!vis[ord[i]]) dfs2(ord[i], i);
}

int main()
{
    int m;
    scanf("%d %d", &b, &m);
    ex.resize((2 << b) + 2);
    for(int i = 0; i < m; i++)
    {
        int a;
        scanf("%d", &a);
        ex[a * 2] = true;
    }
    for(int i = 0; i < (1 << b); i++)
        ex[i * 2 + 1] = true;
    n = (2 << b);
    scc();
    set<int> s;
    for(int i = 0; i < (1 << b); i++)
        if(ex[i * 2]) s.insert(t[i * 2]);
    printf("%d\n", s.size());
}