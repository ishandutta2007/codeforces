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

vector<int> g[1005];
pair<int, int> bad;
vector<pair<int, int> > ans[2];
int col[1005], prv[1005];

void dfs(int s, int cl)
{
    int i;
    col[s]=cl;
    for(i=0; i<g[s].size(); i++)
        if (!col[g[s][i]]) {prv[g[s][i]]=s; dfs(g[s][i], cl);}
        else if (prv[s]!=g[s][i]) bad=make_pair(s, g[s][i]);
}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, a, b, i, j, f, cl;
    vector<int> ::iterator it;
    scanf("%d", &n);
    for(i=1; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    while(1)
    {
        f=0;
        bad=make_pair(0, 0);
        for(i=1; i<=n; i++) col[i]=0;
        cl=1;
        for(i=1; i<=n; i++, cl++)
        {
            if (!col[i]) dfs(i, cl);
            if (!bad.first) continue;
            for(i=1; i<=n; i++) if (col[i]!=cl)
            {
                ans[0].push_back(bad);
                ans[1].push_back(make_pair(bad.first, i));
                break;
            }
            for(it=g[bad.first].begin(); it!=g[bad.first].end(); it++)
                if ((*it)==bad.second) {g[bad.first].erase(it); break;}
            for(it=g[bad.second].begin(); it!=g[bad.second].end(); it++)
                if ((*it)==bad.first) {g[bad.second].erase(it); break;}
            g[bad.first].push_back(i);
            g[i].push_back(bad.first);
            f=1;
            break;      
        }
        if (!f) break;
    }
    printf("%d\n", ans[0].size());
    for(i=0; i<(int)ans[0].size(); i++)
        printf("%d %d %d %d\n", ans[0][i].first, ans[0][i].second, ans[1][i].first, ans[1][i].second);

}