#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=3e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

int n,m,arr[maxn][10],len,brr[maxn];

bool solve(int v)
{
    bool vis[520]={0};
    for(int i=1;i<=n;i++)
    {
        int now=0;
        for(int j=1;j<=m;j++)
        {
            now<<=1;
            if(arr[i][j]>=v)now+=1;
        }
        if(vis[now])return 1;
        now^=len;
        if(!vis[now])
        {
            for(int k=now;k<=len;k++)
            {
                if((k&now)==now)vis[k]=1;
            }
        }
    }
    return 0;
}

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    if(n==1)
    {
        cout<<1<<' '<<1;
        return 0;
    }
    len=(1<<m)-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)scanf("%d",&arr[i][j]);
    }
    int l=0,r=1e9+10;
    while(l<r-1)
    {
        int mid=l+r>>1;
        if(solve(mid))l=mid;
        else r=mid;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            brr[i]<<=1;
            if(arr[i][j]>=l)
            {
                brr[i]+=1;
            }
        }
    }
    bool vis[520]={0};
    int a,b;
    for(int i=1;i<=n;i++)
    {
        if(vis[brr[i]])
        {
            b=i;
            break;
        }
        int now=len^brr[i];
        if(!vis[now])
        {
            for(int k=now;k<=len;k++)
            {
                if((k&now)==now)vis[k]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if((brr[i]|brr[b])==len)
        {
            cout<<i<<' '<<b;
            break;
        }
    }
    return 0;
}