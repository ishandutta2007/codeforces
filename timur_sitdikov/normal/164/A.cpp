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

vector <int> g[2][100005];
char col[2][100005], type[100005], good[100005];
int ind;

void dfs(int s)
{
    int i, sz, tmp;
    col[ind][s]=1;
    good[s]++;
    //if (!ind && type[s]==2) return;
    if (ind==1 && type[s]==1) return;
    sz=g[ind][s].size();
    for(i=0; i<sz; i++)
    {
        tmp=g[ind][s][i];
        if (!ind)
        {
            if (type[tmp]!=1) g[1][tmp].push_back(s);
            if (!col[ind][tmp] && type[tmp]!=1) dfs(tmp);
        }
        else
        {
            if (!col[ind][tmp]) dfs(tmp);
        }
    }
}

int main()
{   
    int n, m, a, b, i, tmp;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++)
    {scanf("%d", &tmp); type[i+1]=(char)tmp;}
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        g[0][a].push_back(b);
    }
    ind=0;
    for(i=1; i<=n; i++)
        if (type[i]==1) dfs(i);
    ind=1;
    for(i=1; i<=n; i++)
        if (type[i]==2 && !col[1][i]) dfs(i);
    for(i=1; i<=n; i++)
        if (good[i]==2) printf("1\n");
        else printf("0\n");

}