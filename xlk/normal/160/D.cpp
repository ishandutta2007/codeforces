#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> ii;
struct E{int x,y,z,r;}e[100020];
bool operator<(const E&a,const E&b)
{
    return a.z<b.z;
}
vector<ii>l[100020];
string ans[100020];
int f[100020];
int dfn[100020];
int low[100020];
int cnt,cur;
int v[100020];
int F(int x)
{
    return f[x]!=x?f[x]=F(f[x]):x;
}
void dfs(int x,int y)
{
    dfn[x]=low[x]=cnt++;
    v[x]=cur;
    for(vector<ii>::iterator i=l[x].begin();i!=l[x].end();i++) 
    {
        int t=i->first;
        int id=i->second;
        if(id==y)
            continue;
        if(v[t]!=cur)
            dfs(t,id),low[x]=min(low[x],low[t]);
        else
            low[x]=min(low[x],dfn[t]);
    }
    if(y!=-1)
    {
        if(low[x]==dfn[x])
        {
            ans[y]="any";   
        }
    }
}
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&e[i].x,&e[i].y,&e[i].z);
        e[i].x--;
        e[i].y--;
        e[i].r=i;
    }
    for(int i=0;i<n;i++)
        f[i]=i;
    sort(e,e+m);
    for(int i=0,j;i<m;i=j)
    {
        for(j=i;j<m&&e[j].z==e[i].z;j++)
            ;
        for(int k=i;k<j;k++)
        {
            E &a=e[k];
            int x=F(a.x),y=F(a.y);
            if(x==y)
                ans[a.r]="none";
            else
                ans[a.r]="at least one";
            l[x].clear();
            l[y].clear();
        }
        for(int k=i;k<j;k++)
        {
            E &a=e[k];
            int x=F(a.x),y=F(a.y);
            if(x!=y)
            {
                l[x].push_back(ii(y,a.r));
                l[y].push_back(ii(x,a.r));
            }
        }
        cur++;
        cnt=0;
        for(int k=i;k<j;k++)
        {
            E &a=e[k];
            int x=F(a.x),y=F(a.y);
            if(x!=y)
            {
                if(v[x]!=cur)
                    dfs(x,-1);
                if(v[y]!=cur)
                    dfs(y,-1);
            }
        }
        for(int k=i;k<j;k++)
        {
            E &a=e[k];
            int x=F(a.x),y=F(a.y);
            f[x]=y;
        }
    }
    for(int i=0;i<m;i++)
        puts(ans[i].c_str());
    return 0;
}