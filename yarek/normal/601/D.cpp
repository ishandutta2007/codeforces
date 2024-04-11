#include <bits/stdc++.h>
using namespace std;

const int A = 26;

struct trie
{
    trie* ch[A];
    int dif;
    
    trie()
    {
        dif = 1;
        for(int i = 0; i < A; i++)
            ch[i] = nullptr;
    }
};

trie* merge(trie *a, trie *b)
{
    if(a == nullptr) return b;
    if(b == nullptr) return a;
    a->dif = 1;
    for(int i = 0; i < 26; i++)
    {
        a->ch[i] = merge(a->ch[i], b->ch[i]);
        if(a->ch[i])
            a->dif += a->ch[i]->dif;
    }
    delete b;
    return a;
}

const int N = 300002;
char s[N];
int c[N];
vector<int> g[N];
int val[N];
trie *root[N];

void dfs(int v, int prev)
{
    trie *node = new trie;
    root[v] = new trie;
    root[v]->ch[s[v]-'a'] = node;
    for(int u: g[v])
        if(u != prev)
        {
            dfs(u, v);
            node = merge(node, root[u]);
        }
    val[v] = node->dif + c[v];
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", c + i);
    scanf("%s", s + 1);
    for(int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    int mx = *max_element(val + 1, val + n + 1);
    printf("%d\n%d\n", mx, count(val + 1, val + n + 1, mx));
}