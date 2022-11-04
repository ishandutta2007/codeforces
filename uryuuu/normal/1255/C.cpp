#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
int a[200005][5];
int v[200005];
int b[200005][5];
int n;
int dd;
int vis[200005];
void dfs(int d,int s)
{
    vis[d]=1;
    if(s==n)
    {
        cout<<d<<endl;
        return;
    }
    cout<<d<<' ';
    if(s==1)
    {
        int id=b[d][1];
        for(int i=1;i<=3;i++)
        {
            if(v[a[id][i]]==2)
            {
                cout<<a[id][i]<<' ';
                vis[a[id][i]]=1;
            }
        }
        for(int i=1;i<=3;i++)
        {
            if(v[a[id][i]]==3)
            {
                dfs(a[id][i],3);
                return;
            }
        }
        return;
    }
    for(int k=1;k<=v[d];k++)
    {
        int id=b[d][k];
        if(vis[a[id][1]]+vis[a[id][2]]+vis[a[id][3]]==2)
        {
            for(int i=1;i<=3;i++)
            {
                if(vis[a[id][i]]==0)
                {
                    dfs(a[id][i],s+1);
                    return;
                }
            }
        }
    }
}
int main()
{
    sync;
    mm(a);
    mm(b);
    mm(v);
    mm(vis);
    cin>>n;
    for(int i=1;i<=n-2;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>a[i][j];
            v[a[i][j]]++;
            b[a[i][j]][v[a[i][j]]]=i;
        }
    }
    int st;
//    int sd;
    for(int i=1;i<=n;i++)
    {
        if(v[i]==1)
        {
            st=i;
//            for(int j=i+1;j<=n;j++)
//            {
//                if(v[j]==1)
//                    sd=1;
//            }
            break;
        }
    }
    vis[st]=1;
    dfs(st,1);
    
    return 0;
}