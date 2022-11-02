/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=120;
const int oo=1000000000;
int AB(int x){if(x<0)return -x;return x;}
char map[V][V*V];
int n,m;
int q[V*V],vis[V*V],cost[V][V*V],top,tail;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        scanf("%s",map[i]);
        memset(cost,-1,sizeof(cost));
        for(int i=0;i<n;i++)
        {
            memset(vis,-1,sizeof(vis));
            top=0;tail=0;
            for(int j=0;j<m;j++)
            if(map[i][j]=='1')
            {
                vis[j]=0;
                tail++;
                q[tail]=j;
            }
            while(top<tail)
            {
                top++;
                int u=q[top];
                cost[i][u]=vis[u];
                int v=u+1;
                if(v>=m)v-=m;
                if(vis[v]==-1)
                {
                    vis[v]=vis[u]+1;
                    tail++;
                    q[tail]=v;
                }
                v=u-1;
                if(v<0)v+=m;
                if(vis[v]==-1)
                {
                    vis[v]=vis[u]+1;
                    tail++;
                    q[tail]=v;
                }
            }
        }
        int ret=-1;
        for(int j=0;j<m;j++)
        {
            int tmp=0;
            for(int i=0;i<n;i++)
            {
                if(cost[i][j]==-1){tmp=-1;break;}
                tmp+=cost[i][j];
            }
            if(tmp==-1)continue;
            if(ret==-1||ret>tmp)ret=tmp;
        }
        printf("%d\n",ret);
    }
}