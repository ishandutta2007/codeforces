#include <iostream>
#include <cstdio>
using namespace std;

const int ALPH = 27;
const int N = (int)1e5 + 100;

struct item
{
    int len, link;
    int next[ALPH];
} tree[N];

int last, sz = 0;
char ans[N];
int par[N];
int h[N];
int indAns = 0;
int minH = (int)1e9, st;

void tree_init()
{
    for (int i = 0; i < N; i++)
        for (int s = 0; s < ALPH; s++)
            tree[i].next[s] = -1;
    last = 0;
    tree[0].len = 0;
    tree[0].link = -1;
    sz = 1;
}

void dfs(int v)
{                          
	for (int i = 0; i < ALPH - 1; i++)
	{
		int to = tree[v].next[i];
		if (to != -1)
		{
			h[to] = h[v] + 1;
			par[to] = v;
			dfs(to);
		}
		else
		{
			if (minH > h[v])
			{
				minH = h[v];
				st = v;
			}
		}
	}
}

void printAns()
{
	for (int i = 0; i < ALPH - 1; i++)
		if (tree[st].next[i] == -1)
		{
			ans[indAns++] = (char)(i + 'a');	
			break;
		}
	while (st != 0)
	{
		int to = par[st];
		for (int i = 0; i < ALPH - 1; i++)
			if (tree[to].next[i] == st)
			{
				ans[indAns++] = (char)(i + 'a');
				break;
			}
		st = to;
	}
	for (int i = indAns - 1; i >= 0; i--)
		putchar(ans[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

    tree_init();
    char a[N];
    char str[N];
    int n;
    scanf("%d\n", &n);
    for (int s = 0; s < n; s++)
    {
        scanf("%s\n", a);   
        int k = strlen(a);     
        a[k] = 'z' + 1;
        a[k + 1] = '\0';  

        strcat(str, a);
    }                  
    int lenStr = strlen(str);   

    for (int i = 0; i < lenStr; i++)
    {
        int c = str[i] - 'a';    
        int cur = sz++;          
        tree[cur].len = tree[last].len + 1;
        int p;
        for (p = last; p != -1; p = tree[p].link)
        {
            if (tree[p].next[c] != -1)
                break;
            tree[p].next[c] = cur;
        }
        if (p == -1)
        {
            tree[cur].link = 0;
            last = cur;
            continue;
        }
        int q = tree[p].next[c];
        if (tree[p].len + 1 == tree[q].len)
            tree[cur].link = q;
        else
        {
            int clone = sz++;
            tree[clone].len = tree[p].len + 1;
            tree[clone].link = tree[q].link;
            for (int s = 0; s < ALPH; s++)  
                tree[clone].next[s] = tree[q].next[s];
            for (;p != -1; p = tree[p].link)
            {
                if (tree[p].next[c] != q)
                    break;
                tree[p].next[c] = clone;
            }
            tree[q].link = tree[cur].link = clone;
        }
        last = cur;
    }                                
                                     

    dfs(0);

    printAns();

    return 0;
}