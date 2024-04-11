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

map<int, vector<int>> g;
map<int, vector<int>>::iterator it;
map<int, int> col;
vector<int> ans;

void dfs(int s)
{
    col[s]=1;
    ans.push_back(s);
    int tmp;
    for(int i=0; i<(int)g[s].size(); i++)
    {
        tmp=g[s][i];
        if (!col[tmp])
            dfs(tmp);
    }
}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, i, a, b;
    cin >> n;
    for(i=0; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        col[a]=0;
        col[b]=0;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(it=g.begin(); it!=g.end(); it++)
        if (it->second.size()==1)
        {
            dfs(it->first);
            break;
        }
    for(i=0; i<(int)ans.size(); i++)
        printf("%d ", ans[i]);
}