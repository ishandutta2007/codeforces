//#include <bits/stdc++.h>
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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;

int father[maxn];

int getf(int x)
{
    if(x==father[x])
        return x;
    return father[x]=getf(father[x]);
}
void jihe(int x,int y)
{
    x=getf(x);
    y=getf(y);
    father[y]=father[x];
}

struct node
{
    int u,v,w;
}e[maxn];

bool cmp(node a,node b)
{
    return a.w<b.w;
}

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        father[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(e+1,e+1+m,cmp);
    
    int ans=0,cnt=0;
    for(int i=1;i<=m;i+=cnt)
    {
        cnt=0;
        while(i+cnt<=m&&e[i+cnt].w==e[i].w)
        {
            int fx=getf(e[i+cnt].v),fy=getf(e[i+cnt].u);
            ans+=(fx!=fy);
            cnt++;
        }
        cnt=0;
        while(i+cnt<=m&&e[i+cnt].w==e[i].w)
        {
            int fx=getf(e[i+cnt].v),fy=getf(e[i+cnt].u);
            if(fx!=fy)
            {
                ans--;
                father[fx]=fy;
            }
            cnt++;
        }
    }
    cout<<ans<<endl;
    return 0;
}