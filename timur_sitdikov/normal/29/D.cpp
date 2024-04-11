#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn=305;
char g[maxn][maxn], col[maxn], col2[maxn], leafs[maxn][maxn], is_leaf[maxn];
int prv[maxn], n;
vector<int> ans;
vector<int> pp;

void dfs(int s)
{
    int i, j, f;
    col[s]=1;
    f=0;
    for(i=1; i<=n; i++)
    {
        if (g[s][i] && !col[i])
        {
            f=1;
            prv[i]=s;
            dfs(i);
            for(j=1; j<=n; j++)
                if (leafs[i][j])
                    leafs[s][j]=1;
        }
    }
    if (!f)
    {
        leafs[s][s]=1;
        is_leaf[s]=1;
    }
}

void go_to_leaf(int s, int lf)
{
    int i;
    for(; s!=lf; )
    {
        ans.push_back(s);
        col2[s]=1;
        for(i=1; i<=n; i++)
            if (g[s][i] && leafs[i][lf] && !col2[i]) 
            {
                s=i;
                break;
            }
    }
    ans.push_back(s);
}

int has_leaf(int s)
{
    int i;
    for(i=1; i<=n; i++)
        if (leafs[s][i] && !col2[i]) 
            return i;
    return 0;

}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int a, b, m, i, j, cur, tmp;
    cin >> n;
    for(i=1; i<n; i++)
    {
        cin >> a >> b;
        g[a][b]=g[b][a]=1;
    }
    while(scanf("%d", &a)==1)
        pp.push_back(a);
    dfs(1);
    go_to_leaf(1, pp[0]);
    cur=pp[0];
    i=0;
    while(i!=pp.size())
    {
        if (is_leaf[cur]) 
        {
            col2[cur]=1;
            i++;
        }
        tmp=has_leaf(cur);
        if (tmp && !leafs[cur][pp[i]])
        {
            printf("-1");
            return 0;
        }
        if (tmp)
        {
            go_to_leaf(cur, pp[i]);
            cur=pp[i];
        }
        else 
        {
            ans.push_back(cur);
            cur=prv[cur];
        }
    }
    for(cur=pp[i-1]; cur; cur=prv[cur])
        ans.push_back(cur);
    printf("1 ");
    for(i=1; i<(int)ans.size(); i++)
        if (ans[i]!=ans[i-1])
            printf("%d ", ans[i]);
    

}