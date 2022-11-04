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
const int maxn=1000005;
const ll Mod=1000000007;

int n,m;
int a[maxn],d[maxn],zx[maxn],zd[maxn];
int pos[maxn];
int lowbit(int x)
{
    return x&(-x);
}

void add(int x,int v)
{
    for(int i=x;i<maxn;i+=lowbit(i))
    {
        d[i]+=v;
    }
}

int query(int x)
{
    int ans=0;
    while(x)
    {
        ans+=d[x];
        x-=lowbit(x);
    }
    return ans;
}

int main()
{
    sync;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        zx[i]=zd[i]=i;
        pos[i]=i+m;
        add(i+m,1);
    }
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        zx[x]=1;
        zd[x]=max(zd[x],query(pos[x]));
        add(pos[x],-1);
        pos[x]=m-i;
        add(pos[x],1);
    }
    for(int i=1;i<=n;i++)
        zd[i]=max(zd[i],query(pos[i]));
    for(int i=1;i<=n;i++)
        cout<<zx[i]<<' '<<zd[i]<<endl;
    return 0;
}