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

vector<int> g[500005], ans[500005];
int col[500005], col2[500005], num[500005], val[500005], top=1;
vector<int> vv[2];
set <int> st;
queue<int> qq;

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, m, a, b, i, j, k, sz, ind, tmp, count;
    scanf("%d %d", &n, &m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(i=1; i<=n; i++)
        if (!col[i])
        {
            col[i]=top;
            sz=g[i].size();
            vv[0].clear();
            st.clear(); 
            for(j=0; j<sz; j++) 
            {
                col2[g[i][j]]=top;
                //num[g[i][j]]=(int)vv[0].size();
                vv[0].push_back(g[i][j]);
                //vv[0].push_back(0);
            }
            while(!qq.empty()) qq.pop();
            for(j=1; j<=n; j++)
                if (!col[j] && col2[j]!=top)
                {col[j]=top; qq.push(j);}
            for(k=0; ; k^=1)
            {
                count=qq.size(); vv[k^1].clear();
                for(j=0; j<(int)vv[k].size(); j++) val[vv[k][j]]=0;
                while(!qq.empty())
                {
                    ind=qq.front();
                    qq.pop();
                    sz=g[ind].size();
                    for(j=0; j<sz; j++)
                    {
                        tmp=g[ind][j];
                        if (col2[tmp]==top) val[tmp]++;
                    }
                }
                for(j=0; j<(int)vv[k].size(); j++)
                    if (val[vv[k][j]]!=count)
                    {
                        qq.push(vv[k][j]); col[vv[k][j]]=top;
                        col2[vv[k][j]]=0;
                    }
                    else { vv[k^1].push_back(vv[k][j]);}
                if (qq.empty()) break;
            }
            top++;
        }
        top--;
    for(i=1; i<=n; i++)
        ans[col[i]].push_back(i);
    printf("%d\n", top);
    for(i=1; i<=top; i++)
    {
        printf("%d ", ans[i].size());
        for(j=0; j<(int)ans[i].size(); j++)
            printf("%d ", ans[i][j]);
        putchar('\n');
    }
}