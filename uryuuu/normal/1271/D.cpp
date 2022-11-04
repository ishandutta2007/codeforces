#include<iostream>
#include<stdio.h>
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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=5005;
const ll Mod=1000000007;


struct node
{
    int a,b,c,id;
}t[maxn];

bool cmp(node a,node b)
{
    if(a.id==b.id)
        return a.c>b.c;
    return a.id<b.id;
}

vector<int>vis;

int s[maxn],d[maxn];
int main()
{
    sync;
    int n,m,k;
    cin>>n>>m>>k;
    s[0]=k;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i].a>>t[i].b>>t[i].c;
        t[i].id=i;
        s[i]=s[i-1]+t[i].b;
        if(s[i-1]<t[i].a)
            f=1;
    }
    if(f)
    {
        cout<<-1<<endl;
        return 0;
    }
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        t[v].id=max(u,t[v].id);
    }
    d[n]=s[n];
    for(int i=n-1;i>=1;i--)
    {
        d[i]=d[i+1];
//        cout<<t[i+1].a<<' '<<s[i]<<endl;
        d[i]=min(s[i]-t[i+1].a,d[i]);
    }
//    for(int i=1;i<=n;i++)
//        cout<<d[i]<<' ';
//    cout<<endl;
    sort(t+1,t+1+n,cmp);
    int sum=0;
    int ss=0;
    for(int i=1;i<=n;i++)
    {
        int id=t[i].id;
        if(d[id]>ss)
        {
            sum+=t[i].c;
            ss++;
            vis.push_back(t[i].c);
        }
        else
        {
            sort(vis.begin(),vis.end());
            if(vis.size()>0)
            {
                if(vis[0]<t[i].c)
                {
                    sum+=(t[i].c-vis[0]);
                    vis[0]=t[i].c;
                }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}