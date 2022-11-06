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

struct state
{
    int v1, v2, dis;
};

const int nmax=505;
vector<int> g[nmax];
char col[nmax][nmax][2];
int prv[nmax][nmax][2], n;
queue<state> qq;
vector<int> ans1, ans2;

void bfs()
{
    state tmp_st, tmp_st1;
    int f=0, i, ind;
    tmp_st.v1=1; 
    tmp_st.v2=n;
    tmp_st.dis=0;
    col[1][n][0]=1;
    qq.push(tmp_st);
    while(!qq.empty())
    {
        tmp_st=qq.front();
        qq.pop();
        if (tmp_st.v1==n && tmp_st.v2==1 && !(tmp_st.dis&1)) 
        {
            f=1;
            break;
        }
        if (!(tmp_st.dis&1))
        {
            for(i=0; i<(int)g[tmp_st.v1].size(); i++)
                if (!col[g[tmp_st.v1][i]][tmp_st.v2][1])
                {
                    col[g[tmp_st.v1][i]][tmp_st.v2][1]=1;
                    prv[g[tmp_st.v1][i]][tmp_st.v2][1]=tmp_st.v1;
                    tmp_st1.v1=g[tmp_st.v1][i];
                    tmp_st1.v2=tmp_st.v2;
                    tmp_st1.dis=tmp_st.dis+1;
                    qq.push(tmp_st1);
                }
        }
        else
        {
            for(i=0; i<(int)g[tmp_st.v2].size(); i++)
                if (!col[tmp_st.v1][g[tmp_st.v2][i]][0] && tmp_st.v1!=g[tmp_st.v2][i])
                {
                    col[tmp_st.v1][g[tmp_st.v2][i]][0]=1;
                    prv[tmp_st.v1][g[tmp_st.v2][i]][0]=tmp_st.v2;
                    tmp_st1.v1=tmp_st.v1;
                    tmp_st1.v2=g[tmp_st.v2][i];
                    tmp_st1.dis=tmp_st.dis+1;
                    qq.push(tmp_st1);
                }
        }
    }
    if (!f)
    {
        printf("-1");
        return;
    }
    printf("%d\n", tmp_st.dis/2);
    for(; tmp_st.dis; )
    {
        if (!(tmp_st.dis&1))
        {
            ans2.push_back(tmp_st.v2);
            tmp_st.v2=prv[tmp_st.v1][tmp_st.v2][0];         
        }
        else
        {
            ans1.push_back(tmp_st.v1);
            tmp_st.v1=prv[tmp_st.v1][tmp_st.v2][1];         
        }
        tmp_st.dis--;
    }
    ans1.push_back(1);
    ans2.push_back(n);
    reverse(ans1.begin(), ans1.end());
    reverse(ans2.begin(), ans2.end());
    for(i=0; i<(int)ans1.size(); i++)
        printf("%d ", ans1[i]);
    putchar('\n');
    for(i=0; i<(int)ans2.size(); i++)
        printf("%d ", ans2[i]);
}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int m, a, b, i;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs();
}